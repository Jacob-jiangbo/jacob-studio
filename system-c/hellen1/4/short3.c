#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kdev_t.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/sched.h>
#include <linux/errno.h>

#include <linux/poll.h>
#include <linux/ioport.h>

#include <linux/kernel.h>
#include <linux/interrupt.h>
#include <linux/workqueue.h>
#include <linux/wait.h>
#include <linux/slab.h>
#include <linux/delay.h>

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

static int share = 0;
module_param(share, int, 0);

static int irq = -1;
volatile int short_irq = -1;
module_param(irq, int, 0);

static int probe = 0;//
module_param(probe, int, 0);//

unsigned long short_buffer = 0;
unsigned long volatile short_head;
unsigned long volatile short_tail;
DECLARE_WAIT_QUEUE_HEAD(short_queue);


MODULE_LICENSE("Dual BSD/GPL");

static inline void short_incr_bp(volatile unsigned long * index, int delta)
{	unsigned long new = *index + delta;
	barrier();
	*index = (new >= (short_buffer + PAGE_SIZE))? short_buffer: new;
}

static int short_open(struct inode * inode, struct file * filp)
{
	extern struct file_operations short_i_fops;

	if(iminor(inode) & 0x80)
		filp->f_op = &short_i_fops;	
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

ssize_t short_i_read(struct file * filp, char __user *buf, size_t cnt, loff_t * ppos)
{
	int count0;
	DEFINE_WAIT(wait);
	
	while(short_head == short_tail)
	{
		prepare_to_wait(&short_queue, &wait, TASK_INTERRUPTIBLE);
		if(short_head == short_tail)
			schedule();
		finish_wait(&short_queue, &wait);
		if(signal_pending (current))
			return 	-ERESTARTSYS;
	}
	count0 = short_head - short_tail;
	if( count0<0 )
		count0 = short_buffer + PAGE_SIZE -short_tail;
	if(count0 < cnt) 	cnt = count0;

	if(copy_to_user(buf, (char*)short_tail, cnt))
		return -EFAULT;
	short_incr_bp (&short_tail, cnt);
	return cnt;
}

ssize_t short_i_write(struct file * filp, const char __user * buf, size_t cnt, loff_t * ppos)
{
	int written = 0, odd = * ppos & 1;
	unsigned long port = short_base;
	void * address = (void *)short_base;
	
	if(use_mem)
	{
		while(written < cnt )
			iowrite8(0xff * ((++written + odd) & 1), address);
	}
	else
	{
		while(written < cnt )
			outb(0xff * ((++written + odd) *1), port);
	}
	*ppos += cnt;
	return written;
}

struct file_operations short_i_fops = 
{
	.owner	=THIS_MODULE,
	.read	=short_i_read,
	.write	=short_i_write,
	.open	=short_open,
	.release=short_release,
};

irqreturn_t short_sh_interrupt(int irq, void * dev_id, struct pt_regs * regs)
{
	int value, written;
	struct timeval tv;

	value = inb(short_base);
	if(!(value &  0x80))
		return IRQ_NONE;

	outb(value & 0x7f, short_base);
	
	do_gettimeofday(&tv);
	written = sprintf((char*) short_head, "%08u.%06u\n", 
				(int)(tv.tv_sec % 100000000), (int)(tv.tv_usec)); 
	short_incr_bp(&short_head, written);
	wake_up_interruptible(&short_queue);
	return 	IRQ_HANDLED;
}

irqreturn_t short_interrupt(int irq, void * dev_id, struct pt_regs * regs)
{
	struct timeval tv;
	int written;

	do_gettimeofday(&tv);

	written = sprintf((char*)short_head, "%08u.%06u\n",
					(int)(tv.tv_sec%100000000), (int)(tv.tv_usec));
	BUG_ON(written != 16);
	short_incr_bp(&short_head, written);
	wake_up_interruptible(&short_queue);
	return IRQ_HANDLED;
}

void short_kernelprobe(void)
{
	int cnt = 0;
	do{
		unsigned long mask;

		mask = probe_irq_on();
		outb_p(0x01, short_base+2);
		outb_p(0x00, short_base);
		outb_p(0xff, short_base);
		outb_p(0x00, short_base+2);
		udelay(5);
		short_irq = probe_irq_off(mask);

		if(short_irq == 0)
		{
			printk(KERN_INFO "short: no irq reported by probe\n");
			short_irq = -1;
		}
	}while(short_irq<0 && cnt++ < 5);
	if(short_irq < 0)
		printk(KERN_INFO "short: probe failed %i times, giving up\n", cnt);
}

irqreturn_t short_probing(int irq, void * dev_id, struct pt_regs * regs)//
{//
	if(short_irq == 0) short_irq = irq;//
	if(short_irq != irq) short_irq = -irq;//
	return IRQ_HANDLED;//
}//

void short_selfprobe(void)//
{//
	int trials[] = {3, 5, 7, 9, 0};//
	int tried[] = {0, 0, 0, 0, 0};//
	int i, cnt = 0;//

	for(i = 0; trials[i]; i++)//
		tried[i] = request_irq(trials[i], short_probing, SA_INTERRUPT, "short probe", NULL);//
	
	do{//
		short_irq = 0;//
		outb_p(0x10, short_base+2);//
		outb_p(0x00, short_base);//
		outb_p(0xff, short_base);//
		outb_p(0x00, short_base+2);//
		udelay(5);//

		if(short_irq == 0)//
		{//
			printk(KERN_INFO "short: no irq report by probe\n");//
		}//
	}while(short_irq <= 0 && cnt < 5);//
	for(i = 0; trials[i]; i++)//
	{//
		if(tried[i]==0)//
			free_irq(trials[i], NULL);//
	}
	if(short_irq < 0)//
		printk(KERN_INFO "short: seltprobe giving up after %i times", cnt);//
}//

static int short_init(void)
{	int result;
	short_base = base;
	short_irq = irq;
	
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

	short_buffer = __get_free_pages(GFP_KERNEL, 0);
	short_head = short_tail = short_buffer;	

	if(short_irq < 0 && probe ==1)//
		short_kernelprobe();
	if(short_irq < 0 && probe ==2)//
		short_selfprobe();//
	if(short_irq < 0)//
		switch(short_base)//
		{//
			case 0x378: short_irq = 7; break;//
			case 0x278: short_irq = 2; break;//
			case 0x3bc: short_irq = 5; break;//
		}//

	if(short_irq >= 0 && share > 0)
	{	
		result = request_irq(short_irq, short_sh_interrupt,
							SA_SHIRQ | SA_INTERRUPT, 
							"short", short_sh_interrupt);
		if(result)
		{
			printk(KERN_INFO "short: can't get assigned irq %i\n", short_irq);
			short_irq = -1;
		}
		else
		{
			outb(0x10, short_base+2);	
		}
		return 0;
	}

	if(short_irq >= 0)
	{
		result = request_irq(short_irq, short_interrupt,
						SA_INTERRUPT, "short", NULL);
		if(result)
		{
			printk(KERN_INFO "short: can't get assigned irq %i\n", short_irq);
			short_irq = -1;
		}
		else
		{
			outb(0x10, short_base+2);
		}	
	}
	return 0;
}

static void short_exit(void)
{
	if(short_irq >= 0)
	{
		outb(0x0, short_base+2);
	}

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

