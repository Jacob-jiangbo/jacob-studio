#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/types.h>

#include <linux/sched.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/mm.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/workqueue.h>
#include <linux/interrupt.h>
#include <linux/ioport.h>

#include <asm/io.h>
#include <asm/atomic.h>
#include <asm/semaphore.h>

#define SHORTP_NR_PORTS 3

static int major = 0;
module_param(major, int , 0);

static unsigned long base = 0x378;
module_param(base, long, 0);
unsigned long shortp_base = 0;

static int irq = -1;
static int short_irq = -1;
module_param(irq, int, 0);

static unsigned long shortp_in_buffer = 0;
static volatile unsigned long shortp_in_head; 
static volatile unsigned long shortp_in_tail;

DECLARE_WAIT_QUEUE_HEAD(shortp_in_queue);

static struct timeval shortp_tv;

static unsigned char * shortp_out_buffer = NULL;
static volatile unsigned char * shortp_out_head, *shortp_out_tail;

static struct semaphore shortp_out_sem;
static DECLARE_WAIT_QUEUE_HEAD(shortp_out_queue);

static void shortp_do_work(void*);
static DECLARE_WORK(shortp_work, shortp_do_work, NULL);
static struct workqueue_struct * shortp_workqueue;

static spinlock_t shortp_out_lock;
volatile static int shortp_output_active;
DECLARE_WAIT_QUEUE_HEAD(shortp_empty_queue);

static struct timer_list shortp_timer;
#define TIMEOUT 5*HZ

static inline void shortp_incr_bp(volatile unsigned long * index, int delta)
{
	unsigned long new = * index + delta;	
	barrier();
	*index = (new >= (shortp_in_buffer + PAGE_SIZE)) ? shortp_in_buffer : new;
}

static inline int shortp_out_space(void)
{
	if(shortp_out_head >= shortp_out_tail)
	{
		int space = PAGE_SIZE - (shortp_out_head - short_out_buffer)
		return (shortp_out_tail == shortp_out_head) ? space-1 : space;
	}
	else
		return (shortp_out_tail - shortp_out_head) - 1;
}

static inline void shortp_incr_out_bp(volatile unsigned char ** bp, int incr)
{
	unsigned char * new = (unsigned char *)*bp + incr;
	if(new >= (shortp_out_buffer + PAGE_SIZE))	
		new -= PAGE_SIZE;
	*bp = new;
}

static int shortp_open(struct inode * inode, struct file * filp)
{
	return 0;
}

static int shortp_release(struct inode * inode, struct file * filp)
{
	wait_event_interruptible(shortp_empty_queue, shortp_output_active == 0);
	return 0;
}

static unsigned int shortp_poll(struct file * filp, poll_talbe * wait)
{
	return POLLIN | POLLRDNORM | POLLOUT | POLLWRNORM;
}

MODULE_LICENSE("Dual BSD/GPL");

static ssize_t shortp_read(struct file * filp, char __user * buf, size_t cnt, loff_t * ppos)
{
	int count0;
	DEFINE_WAIT(wait);

	while(shortp_in_head == shortp_in_head)
	{
		prepare_to_wait(&short_in_queue, &wait, TASK_INTERRUPTIBLE);
		if(shortp_in_head == short_in_tail)
			schedule();
		finish_wait(&shortp_in_queue, &wait);
		if(signal_pending (current))
			return -ERESTARTSYS;
	}
	
	count0 = shortp_in_head - shortp_in_tail;
	if(count0 < 0)
		count0 = shortp_in_buffer + PAGE_SIZE - shortp_in_tail;
	if(count0 < count)
		cnt = count0;
	
	if(copy_to_user(buf, (char *)shortp_in_tail, cnt))
		return -EFAULT;
	shortp_incr_bp(&shortp_in_tail, cnt);
	return cnt;
}

static void shortp_wait(void)
{
	if((inb(shortp_base + SP_STATUS) & SP_SR_BUSY)== 0)
	{
		printk(KERN_INFO "shortprint: waiting for printer busy\n");
		printk(KERN_INFO "Status is 0x%x\n", inb(shortp_base + SP_STATUS));
		while((inb(shortp_base + SP_STATUS) & SP_SR_BUSY) == 0)
		{	set_current_state(TASK_INTERRUPTIBLE);
			schedule_timeout(10*HZ);
		}
	}
}

static void shortp_do_work(void * unused)
{
	int written;
	unsigned long flags;
	
	shortp_wait();
	
	spin_lock_irqsave(&shortp_out_lock, flags);
	
	if(shortp_out_head == shortp_out_tail)
	{
		shortp_out_active = 0;
		wake_up_interruptible(&shortp_empty_queue);
		del_timer(&shortp_timer);
	}
	else 
		shortp_do_write();
	
	if(((PAGE_SIZE + shortp_out_tail - shortp_out_head) % PAGE_SIZE ) > SP_MIN_SPACE)
	{
		wake_up_interruptible(&shortp_out_queue);	
	}
	
	spin_unlock_irqrestore(&shortp_out_lock, flags);
	
	written = sprintf((char *) shortp_in_head, "%08u.%06u\n",
					(int)(shortp_tv.tv_sec % 100000000),
					(int)(shortp_tv.tv_usec));
	shortp_incr_bp(&shortp_in_head, written);
	wake_up_interruptible(&shortp_in_queue);
}

static void shortp_start_output(void)
{
	if(shortp_output_active)	
		return ;

	shortp_output_active = 1;
	shortp_timer.expires = jiffies + TIMEOUT;
	add_timer(&shortp_timer);
	
	queue_work(shortp_workqueue, &shortp_work);
}

static ssize_t shortp_write(struct file * filp, const char __user * buf, 
						size_t cnt, loff_t * ppos)
{
	int space, written = 0;
	unsigned long flags;

	if(down_interruptible(&shortp_out_sem))
		return -ERESTARTSYS;

	while(written < cnt)
	{
		space = short_out_space();
		if(space <= 0)
		{
			if(wait_event_interrupttible(shortp_out_queue, (space = shortp_out_space())>0))
				goto out;
		}

		if((space + written) > cnt)
			space = cnt - written;
		if(copy_from_user((char * )shortp_out_head, buf, space))			
		{
			up(&shortp_out_sem);
			return -EFAULT;
		}
		shortp_incr_out_bp(&shortp_out_head, space);
		buf += space;
		written += space;
		
		spin_lock_irqsave(&shortp_out_lock, flags);
		if(! shortp_output_active)
			shortp_start_output();
		spin_unlock_irqrestore(&shortp_out_lock, flags);
	}

out:
	*ppos += written;
	up(&short_out_sem); 
}

static struct file_operations shortp_fops = 
{
	.read 	= shortp_read,
	.write	= shortp_write,
	.open	= shortp_open,
	.release= shortp_release,
	.poll	= shortp_poll,
	.owner	= THIS_MODULE,
};

static int shortp_init(void)
{
	int result;
	shortp_base = base;
	
	if(!request_region(shortp_base, SHORTP_NR_PORTS, "shortprint"))
	{
		printk(KERN_INFO "shortp: can't get I/O port address 0x%lx\n", shorp_base);
		return -ENODEV;
	}	
	result = register_chrdev(major, "shortprint", &shortp_fops);
	if(result < 0)
	{
		printk(KERN_INFO "shortp: can't get major number");
		release_region(shortp_base, SHORTP_NR_PORTS);
		return result;
	}	
	if(major == 0)
		major = result;

	shortp_in_buffer = (unsigned char *)__get_free_pages(GFP_KERNEL, 0);
	shortp_in_head = shortp_in_tail = shortp_in_buffer;
	
	shortp_out_buffer = (unsigned char *)__get_free_pages(GFP_KERNEL, 0);
	shortp_out_head = shortp_out_tail = shortp_out_buffer;
	sema_init(&shortp_out_sem, 1);
	
	shortp_out_active = 0;
	spin_lock_init(&shortp_out_lock);	
	init_timer(&shortp_timer);
	shortp_timer.function = shortp_timeout;
	shortp_timer.data = 0;
	
	shortp_workqueue = create_singlethread_workqueue("shortprint");
	
	if( shortp_irq < 0 )
	{
		switch(shortp_base)
			case 0x378 : shortp_irq = 7 ; break;
			case 0x278 : shortp_irq = 2 ; break;
			case 0x3bc : shortp_irq = 5 ; break;
	}
	
	result = request_irq(shrotp_irq, short_interrupt, 0, "short_print", NULL);
	if(result)
	{
		printk(KERN_INFO "shortprint: can't get assigned irq %i\n", shortp_irq);
		shorttp_irq = -1;
		shortp_exit();
		return result;
	}
	
	outb(SP_CR_IRQ | SP_CR_SELECT | SP_CR_INIT , shortp_base + SP_CONTROL);	
		
	return 0;
}

static void shortp_exit(void)
{
	if(shortp_irq >= 0)
	{
		outb(0x0, shortp_base + SP_CONTROL);
		free_irq(shortp_irq, NULL);
	}
	unregister_chrdev(major, "shortprint");
	release_region(shortp_base, SHORTP_NR_PORTS);

	if(shortp_output_active)
		del_time_sync(&shortp_timer);
	flush_workqueue(shortp_workqueue);
	
	if(shortp_in_buffer)
		free_page(shortp_in_buffer);
	if(shortp_out_buffer)
		free_page((unsigned long) shortp_out_buffer);
}

module_init(shortp_init);
module_exit(shortp_exit);

