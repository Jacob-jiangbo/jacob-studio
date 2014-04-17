#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/cdev.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/sched.h>
#include <linux/errno.h>

#include <linux/poll.h>
#include <linux/ioport.h>

#include <linux/kernel.h>
#include <linux/interrupt.h>


#include <asm/io.h>
#include <asm/system.h>
#include <asm/uaccess.h>

#define SHORT_NR_PORTS 8

static int major = 0;
module_param(major, int , 0);
static int use_mem = 0;
module_param(use_mem, int , 0);
static unsigned long base = 0x378;
module_param(base, long, 0);
unsigned long short_base = 0;

MODULE_LICENSE("Dual BSD/GPL");

static int short_open(struct inode * inode, struct file * filp)
{
	return 0;
}

static int short_release(struct inode * inode, struct file * filp)
{
	return 0;
}

enum short_modes {SHORT_DEFAULT = 0, SHORT_PAUSE, SHORT_STRING, SHORT_MEMORY};

ssize_t do_short_read(struct inode * inode, struct file * filp,
					char __user * buf, size_t cnt,loff_t * ppos)
{
	int ret = cnt, minor = iminor(inode);
	unsigned long port = short_base + (minor&0x0f);
	void * address = (void *)short_base + (minor&0x0f);
	int mode = (minor&0x70)>>4;
	unsigned char * kbuf = kmalloc(sizeof(cnt) , GFP_KERNEL), *ptr;
	if(!kbuf)
		return -ENOMEM;
	ptr = kbuf;
	if(use_mem)
		mode = SHORT_MEMORY;
	switch(mode)
	{
		case SHORT_DEFAULT:
			while(cnt--)
			{
				*(ptr++) = inb(port);
				rmb();
			}
			break;
		case SHORT_PAUSE:
			while(cnt--)
			{
				*(ptr++) = inb_p(port);
				rmb();
			}
			break;
		case SHORT_MEMORY:
			while(cnt--)
			{
				*(ptr++) = ioread8(address);
				rmb();
			}
			break;
		case SHORT_STRING:
			insb(port, ptr, cnt);
			rmb();
			break;
		default:
			return -EINVAL;
		break;
	}
	if(ret > 0 && copy_to_user(buf, kbuf, cnt))
		return -EFAULT;
	kfree(kbuf);
	return ret;
}

ssize_t short_read(struct file * filp, char __user * buf, size_t cnt, loff_t * ppos)
{
	return do_short_read(filp->f_dentry->d_inode, filp, buf, cnt, ppos);
}

ssize_t do_short_write(struct inode * inode, struct file * filp, const char __user * buf, 
						size_t cnt , loff_t * ppos)
{
	int ret = cnt, minor = iminor(inode);
	unsigned long port = short_base + (minor&0x0f);
	void * address = (void*)short_base + (minor&0x0f);
	int mode = (minor&0x70) >> 4;
	unsigned char * kbuf = kmalloc(sizeof(cnt), GFP_KERNEL), *ptr;
	if(!kbuf)
		return -ENOMEM;
	if(copy_from_user(kbuf, buf, cnt));
		return -EFAULT;
	ptr = kbuf;
	if(use_mem)
		mode = SHORT_MEMORY;
	
	switch(mode)
	{
		case SHORT_DEFAULT:
			while(cnt--)
			{	outb(*(ptr++), port);
				wmb();
			}
			break;
		case SHORT_PAUSE:
			while(cnt--)
			{
				outb_p(*(ptr++), port);
				wmb();
			}
			break;
		case SHORT_MEMORY:
			while(cnt--)
			{
				iowrite8(*(ptr++), address);
				wmb();
			}
			break;
		case SHORT_STRING:
			outsb(port, ptr, cnt);
			wmb();
			break;
		default:
			return -EINVAL;
	}
	return ret;
}

ssize_t short_write(struct file * filp, const char __user * buf, size_t cnt, loff_t * ppos)
{
	return do_short_write(filp->f_dentry->d_inode, filp, buf, cnt, ppos);
}

unsigned int short_poll(struct file * filp, poll_table * wait)
{
	return POLLIN | POLLRDNORM | POLLOUT | POLLWRNORM;
}

static struct file_operations short_fops = 
{	
	.owner 		= THIS_MODULE,
	.open 		= short_open,
	.release 	= short_release,
	.read 		= short_read,
	.write 		= short_write,
	.poll 		= short_poll,
};

static int short_init(void)
{	int result;
	short_base = base;
	if(!use_mem)
	{
		if(!request_region(short_base, SHORT_NR_PORTS, "short"))
		{
			printk(KERN_INFO "short: can't get port address 0x%lx\n", short_base);
			return -ENODEV;
		}
	}
	else
	{
		if(!request_mem_region(short_base, SHORT_NR_PORTS, "short"))
		{
			printk(KERN_INFO "short: can't get port address 0x%lx\n", short_base);
			return -ENODEV;
		}
		short_base = (unsigned long)ioremap(short_base, SHORT_NR_PORTS);
	}
	result = register_chrdev(major, "short", &short_fops);	
	if(result < 0)
	{
		printk(KERN_INFO "short: can't get major number");
		release_region(short_base, SHORT_NR_PORTS);
	}
	if(major==0) major = result;
	return 0;
}

static void short_exit(void)
{
	unregister_chrdev(major, "short");
	if(use_mem)
	{
		iounmap((void __iomem *)short_base);
		release_mem_region(short_base, SHORT_NR_PORTS);
	}
	else
	{
		release_region(short_base, SHORT_NR_PORTS);	
	}
}

module_init(short_init);
module_exit(short_exit);

