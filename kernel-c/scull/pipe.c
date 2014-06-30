/*
 * pipe.c -- fifo driver for scull
 *
 * Copyright (C) 2001 Alessandro Rubini and Jonathan Corbet
 * Copyright (C) 2001 O'Reilly & Associates
 *
 * The source code in this file can be freely used, adapted,
 * and redistributed in source or binary form, so long as an
 * acknowledgment appears in derived source files.  The citation
 * should list that the code comes from the book "Linux Device
 * Drivers" by Alessandro Rubini and Jonathan Corbet, published
 * by O'Reilly & Associates.   No warranty is attached;
 * we cannot take responsibility for errors or fitness for use.
 *
 */
 
#include <linux/module.h>
#include <linux/moduleparam.h>

#include <linux/kernel.h>	/* printk(), min() */
#include <linux/slab.h>		/* kmalloc() */
#include <linux/fs.h>		/* everything... */
#include <linux/proc_fs.h>
#include <linux/errno.h>	/* error codes */
#include <linux/types.h>	/* size_t */
#include <linux/fcntl.h>
#include <linux/poll.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>

//WJB: declear for "TASK_INTERRUPTIBLE"
#include <linux/sched.h>

#include "scull.h"		/* local definitions */

struct scull_pipe {
        wait_queue_head_t inq, outq;       /* read and write queues */
        char *buffer, *end;                /* begin of buf, end of buf */
        int buffersize;                    /* used in pointer arithmetic */
        char *rp, *wp;                     /* where to read, where to write */
        int nreaders, nwriters;            /* number of openings for r/w */
        struct fasync_struct *async_queue; /* asynchronous readers */
        struct semaphore sem;              /* mutual exclusion semaphore */
        struct cdev cdev;                  /* Char device structure */
};

/* parameters */
static int scull_p_nr_devs = SCULL_P_NR_DEVS;	/* number of pipe devices */
int scull_p_buffer =  SCULL_P_BUFFER;	/* buffer size */
dev_t scull_p_devno;			/* Our first device number */

module_param(scull_p_nr_devs, int, 0);	/* FIXME check perms */
module_param(scull_p_buffer, int, 0);

static struct scull_pipe *scull_p_devices;

static int scull_p_fasync(int fd, struct file *filp, int mode);
static int spacefree(struct scull_pipe *dev);

 /*----------------------------------------------------------------------\
函数名：scull_p_open											   
描  述：	scull_p 设备的open函数								  
输  入：	inode 	:在内核内部表示文件												   
 		filp 		:表示打开的文件								   
输  出：	无																   
返  回：												   									   
 \----------------------------------------------------------------------*/
static int scull_p_open(struct inode *inode, struct file *filp)
{
	struct scull_pipe *dev;

	dev = container_of(inode->i_cdev, struct scull_pipe, cdev);
	filp->private_data = dev;

	if (down_interruptible(&dev->sem) != 0)
	{
		return -ERESTARTSYS;
	}
	if (NULL == dev->buffer) 
	{
		/* allocate the buffer */
		dev->buffer = kmalloc(scull_p_buffer, GFP_KERNEL);
		if (NULL == dev->buffer) 
		{
			up(&dev->sem);
			return -ENOMEM;
		}
	}
	dev->buffersize = scull_p_buffer;
	dev->end = dev->buffer + dev->buffersize;
	dev->rp = dev->wp = dev->buffer; /* rd and wr from the beginning */

	/* use f_mode,not  f_flags: it's cleaner (fs/open.c tells why) */
	if (filp->f_mode & FMODE_READ)
	{
		dev->nreaders++;
	}
	if (filp->f_mode & FMODE_WRITE)
	{
		dev->nwriters++;
	}
	up(&dev->sem);

	return nonseekable_open(inode, filp);
}

 /*----------------------------------------------------------------------\
函数名：scull_p_release											   
描  述：	scull_p 设备的open函数								  
输  入：	inode 	:在内核内部表示文件												   
 		filp 		:表示打开的文件								   
输  出：	无																   
返  回：												   									   
 \----------------------------------------------------------------------*/
static int scull_p_release(struct inode *inode, struct file *filp)
{
	struct scull_pipe *dev = filp->private_data;

	/* remove this filp from the asynchronously notified filp's */
	scull_p_fasync(-1, filp, 0);
	down(&dev->sem);
	if (filp->f_mode & FMODE_READ)
		dev->nreaders--;
	if (filp->f_mode & FMODE_WRITE)
		dev->nwriters--;
	if (dev->nreaders + dev->nwriters == 0) {
		kfree(dev->buffer);
		dev->buffer = NULL; /* the other fields are not checked on open */
	}
	up(&dev->sem);
	return 0;
}

 /*----------------------------------------------------------------------\
 函数名：scull_p_read											
 描  述：	scull_p设备的读函数(阻塞操作为简单睡眠方式)								
 输  入：	filp 	代表一个打开的文件													   
		buf 	待读入用户空间的起始地址									   
 		count 	待读入的数目											  
 		f_pos 	打开文件指针位置												   
 输  出：	无																   
 * 返  回：ssize_t  写入的数目													   			   
 \----------------------------------------------------------------------*/
static ssize_t scull_p_read (struct file *filp, char __user *buf, size_t count,
                loff_t *f_pos)
{
	struct scull_pipe *dev = filp->private_data;

	if (down_interruptible(&dev->sem) != 0)
	{
		return -ERESTARTSYS;
	}

	while (dev->rp == dev->wp) 
	{ 	/* nothing to read */
		up(&dev->sem); /* release the lock */
		
		if (filp->f_flags & O_NONBLOCK)
		{
			return -EAGAIN;
		}
		PDEBUG("\"%s\" reading: going to sleep\n", current->comm);
		if (wait_event_interruptible(dev->inq, (dev->rp != dev->wp)) != 0)
		{
			return -ERESTARTSYS; /* signal: tell the fs layer to handle it */
		}
		/* otherwise loop, but first reacquire the lock */
		if (down_interruptible(&dev->sem))
		{
			return -ERESTARTSYS;
		}
	}
	
	/* ok, data is there, return something */
	if (dev->wp > dev->rp)
	{
		count = min(count, (size_t)(dev->wp - dev->rp));
	}
	else /* the write pointer has wrapped, return data up to dev->end */
	{
		count = min(count, (size_t)(dev->end - dev->rp));
	}

	if (copy_to_user(buf, dev->rp, count) != 0) 
	{
		up (&dev->sem);
		return -EFAULT;
	}
	
	dev->rp += count;
	if (dev->rp == dev->end)
	{
		dev->rp = dev->buffer; /* wrapped */
	}
	up (&dev->sem);

	/* finally, awake any writers and return */
	wake_up_interruptible(&dev->outq);
	PDEBUG("\"%s\" did read %li bytes\n",current->comm, (long)count);
	return count;
}

 /*----------------------------------------------------------------------\
 函数名：  scull_getwritespace											   	
 描  述：	等待scull_p 设备的写空间(阻塞操作为高级睡眠方式)			   								
 输  入：	dev	 	:scull_p 设备结构体										
 		 filp		:设备对应的打开文件描述结构体 							
  输  出：	无											   					
 返  回：	int		: int 是否有写空间											
                                        	0 : 有写空间												
                                       		1 : 无写空间												
 \----------------------------------------------------------------------*/
static int scull_getwritespace(struct scull_pipe *dev, struct file *filp)
{
	while (spacefree(dev) == 0) 
	{ /* full */
		DEFINE_WAIT(wait);
		
		up(&dev->sem);
		if (filp->f_flags & O_NONBLOCK)
		{
			return -EAGAIN;
		}
		
		PDEBUG("\"%s\" writing: going to sleep\n",current->comm);
		
		prepare_to_wait(&dev->outq, &wait, TASK_INTERRUPTIBLE);
		
		if (spacefree(dev) == 0)
		{
			schedule();
		}
		finish_wait(&dev->outq, &wait);
		
		if (signal_pending(current) != 0)
		{
			return -ERESTARTSYS; /* signal: tell the fs layer to handle it */
		}

		if (down_interruptible(&dev->sem) != 0)
		{
			return -ERESTARTSYS;
		}
	}
	return 0;
}	

 /*----------------------------------------------------------------------\
 函数名：  spacefree											   
 描  述：参看设备有多少剩余空间						   
 输  入：dev	 	:scull_p 设备结构体											   
 输  出：无											   
 返  回：int		: scull_p 设备空闲空间												   
 \----------------------------------------------------------------------*/
static int spacefree(struct scull_pipe *dev)
{
	if (dev->rp == dev->wp)
	{
		return dev->buffersize - 1;
	}
	return ((dev->rp + dev->buffersize - dev->wp) % dev->buffersize) - 1;
}

 /*----------------------------------------------------------------------\
 函数名：scull_p_write										
 描  述：								   
 输  入：	filp 		代表一个打开的文件													   
		buf 		待读入用户空间的起始地址									   
		count 	待读入的数目											   
		f_pos 	打开文件指针位置												   
 输  出：无																   
 返  回：ssize_t  写入的数目													   
 \----------------------------------------------------------------------*/
static ssize_t scull_p_write(struct file *filp, const char __user *buf, size_t count,
                loff_t *f_pos)
{
	struct scull_pipe *dev = filp->private_data;
	int result = 0;

	if (down_interruptible(&dev->sem) != 0)
	{
		return -ERESTARTSYS;
	}

	/* Make sure there's space to write */
	result = scull_getwritespace(dev, filp);
	if (result != 0)
	{
		return result; /* scull_getwritespace called up(&dev->sem) */
	}

	/* ok, space is there, accept something */
	count = min(count, (size_t)spacefree(dev));
	if (dev->wp >= dev->rp)
	{
		count = min(count, (size_t)(dev->end - dev->wp)); /* to end-of-buf */
	}
	else /* the write pointer has wrapped, fill up to rp-1 */
	{
		count = min(count, (size_t)(dev->rp - dev->wp - 1));
	}
	
	PDEBUG("Going to accept %li bytes to %p from %p\n", (long)count, dev->wp, buf);
	
	if (copy_from_user(dev->wp, buf, count)) 
	{
		up (&dev->sem);
		return -EFAULT;
	}
	
	dev->wp += count;
	if (dev->wp == dev->end)
	{
		dev->wp = dev->buffer; /* wrapped */
	}
	
	up(&dev->sem);

	/* finally, awake any reader */
	wake_up_interruptible(&dev->inq);  /* blocked in read() and select() */

	/* and signal asynchronous readers, explained late in chapter 5 */
	if (dev->async_queue)
	{
		kill_fasync(&dev->async_queue, SIGIO, POLL_IN);
	}
	
	PDEBUG("\"%s\" did write %li bytes\n",current->comm, (long)count);
	
	return count;
}

static unsigned int scull_p_poll(struct file *filp, poll_table *wait)
{
	struct scull_pipe *dev = filp->private_data;
	unsigned int mask = 0;

	/*
	 * The buffer is circular; it is considered full
	 * if "wp" is right behind "rp" and empty if the
	 * two are equal.
	 */
	down(&dev->sem);
	poll_wait(filp, &dev->inq,  wait);
	poll_wait(filp, &dev->outq, wait);
	if (dev->rp != dev->wp)
		mask |= POLLIN | POLLRDNORM;	/* readable */
	if (spacefree(dev))
		mask |= POLLOUT | POLLWRNORM;	/* writable */
	up(&dev->sem);
	return mask;
}





static int scull_p_fasync(int fd, struct file *filp, int mode)
{
	struct scull_pipe *dev = filp->private_data;

	return fasync_helper(fd, filp, mode, &dev->async_queue);
}



/* FIXME this should use seq_file */
#ifdef SCULL_DEBUG
static void scullp_proc_offset(char *buf, char **start, off_t *offset, int *len)
{
	if (*offset == 0)
		return;
	if (*offset >= *len) {	/* Not there yet */
		*offset -= *len;
		*len = 0;
	}
	else {			/* We're into the interesting stuff now */
		*start = buf + *offset;
		*offset = 0;
	}
}


static int scull_read_p_mem(char *buf, char **start, off_t offset, int count,
		int *eof, void *data)
{
	int i, len;
	struct scull_pipe *p;

#define LIMIT (PAGE_SIZE-200)	/* don't print any more after this size */
	*start = buf;
	len = sprintf(buf, "Default buffersize is %i\n", scull_p_buffer);
	for(i = 0; i<scull_p_nr_devs && len <= LIMIT; i++) {
		p = &scull_p_devices[i];
		if (down_interruptible(&p->sem))
			return -ERESTARTSYS;
		len += sprintf(buf+len, "\nDevice %i: %p\n", i, p);
/*		len += sprintf(buf+len, "   Queues: %p %p\n", p->inq, p->outq);*/
		len += sprintf(buf+len, "   Buffer: %p to %p (%i bytes)\n", p->buffer, p->end, p->buffersize);
		len += sprintf(buf+len, "   rp %p   wp %p\n", p->rp, p->wp);
		len += sprintf(buf+len, "   readers %i   writers %i\n", p->nreaders, p->nwriters);
		up(&p->sem);
		scullp_proc_offset(buf, start, &offset, &len);
	}
	*eof = (len <= LIMIT);
	return len;
}


#endif



/*
 * The file operations for the pipe device
 * (some are overlayed with bare scull)
 */
struct file_operations scull_pipe_fops = {
	.owner =	THIS_MODULE,
	.llseek =	no_llseek,
	.read =		scull_p_read,
	.write =	scull_p_write,
	.poll =		scull_p_poll,
	.unlocked_ioctl =	scull_ioctl,
	.open =		scull_p_open,
	.release =	scull_p_release,
	.fasync =	scull_p_fasync,
};


 /*----------------------------------------------------------------------\
 函数名：scull_p_setup_cdev											   
 描  述：	pipe 设备驱动程序初始化函数(主要完成cdev的填充)								   
 输  入：	dev 	 	:PIPE设备设备结构体
 		index	:设备索引号
 输  出：	无																   
 返  回：	无										  							   
 \----------------------------------------------------------------------*/
static void scull_p_setup_cdev(struct scull_pipe *dev, int index)
{
	int err, devno = scull_p_devno + index;
    
	cdev_init(&dev->cdev, &scull_pipe_fops);
	dev->cdev.owner = THIS_MODULE;
	err = cdev_add (&dev->cdev, devno, 1);
	/* Fail gracefully if need be */
	if (err != 0)
	{
		printk(KERN_NOTICE "Error %d adding scullpipe%d", err, index);
	}
}

 /*----------------------------------------------------------------------\
函数名：scull_p_init											
 描  述：pipe 设备驱动程序初始化函数	Initialize the pipe devs							
 输  入：firstdev 	 	:PIPE设备号									 
 输  出：无																 
 返  回：int			:初始化PIPE设备的数目															  							   
 \----------------------------------------------------------------------*/
int scull_p_init(dev_t firstdev)
{
	int i, result;

	result = register_chrdev_region(firstdev, scull_p_nr_devs, "scullp");
	if (result < 0) 
	{
		printk(KERN_NOTICE "Unable to get scullp region, error %d\n", result);
		return 0;
	}
	scull_p_devno = firstdev;
	scull_p_devices = kmalloc(scull_p_nr_devs * sizeof(struct scull_pipe), GFP_KERNEL);
	if (scull_p_devices == NULL) 
	{
		unregister_chrdev_region(firstdev, scull_p_nr_devs);
		return 0;
	}
	memset(scull_p_devices, 0, scull_p_nr_devs * sizeof(struct scull_pipe));
	for (i = 0; i < scull_p_nr_devs; i++) {
		init_waitqueue_head(&(scull_p_devices[i].inq));
		init_waitqueue_head(&(scull_p_devices[i].outq));
		//WJB: init_MUTEX(&scull_p_devices[i].sem);
		sema_init(&scull_p_devices[i].sem, 1);
		scull_p_setup_cdev(scull_p_devices + i, i);
	}
#ifdef SCULL_DEBUG
	create_proc_read_entry("scullpipe", 0, NULL, scull_read_p_mem, NULL);
#endif
	return scull_p_nr_devs;
}

/*
 * This is called by cleanup_module or on failure.
 * It is required to never fail, even if nothing was initialized first
 */
void scull_p_cleanup(void)
{
	int i;

#ifdef SCULL_DEBUG
	remove_proc_entry("scullpipe", NULL);
#endif

	if (!scull_p_devices)
		return; /* nothing else to release */

	for (i = 0; i < scull_p_nr_devs; i++) {
		cdev_del(&scull_p_devices[i].cdev);
		kfree(scull_p_devices[i].buffer);
	}
	kfree(scull_p_devices);
	unregister_chrdev_region(scull_p_devno, scull_p_nr_devs);
	scull_p_devices = NULL; /* pedantic */
}
