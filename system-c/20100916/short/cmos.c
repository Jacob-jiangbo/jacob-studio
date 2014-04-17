/*
 * short.c -- Simple Hardware Operations and Raw Tests
 */

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>

#include <linux/sched.h>
#include <linux/kernel.h>	/* printk() */
#include <linux/fs.h>		/* everything... */
#include <linux/errno.h>	/* error codes */
#include <linux/delay.h>	/* udelay */
#include <linux/kdev_t.h>
#include <linux/slab.h>
#include <linux/mm.h>
#include <linux/ioport.h>
#include <linux/poll.h>
#include <linux/wait.h>

#include <asm/io.h>

MODULE_LICENSE("Dual BSD/GPL");


int short_open (struct inode *inode, struct file *filp)
{
	return 0;
}


int short_release (struct inode *inode, struct file *filp)
{
	return 0;
}


/*
 * Version-specific methods for the fops structure.  FIXME don't need anymore.
 */
ssize_t short_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
        unsigned char *kbuf = kmalloc(count, GFP_KERNEL);
        *(kbuf) = inb(0x71);
        rmb();
	count = copy_to_user(buf, kbuf, count); 
	kfree(kbuf);
	return 1;
}

ssize_t short_write(struct file *filp, const char __user *buf, size_t count,
		loff_t *f_pos)
{
        unsigned char *kbuf = kmalloc(count, GFP_KERNEL); 
        count = copy_from_user(kbuf, buf, count);
        outb(*(kbuf), 0x70);
        wmb();
        kfree(kbuf); 
	return 1;
}

struct file_operations short_fops = {
	.owner	 = THIS_MODULE,
	.read	 = short_read,
	.write	 = short_write,
	.open	 = short_open,
	.release = short_release,
};

/* Finally, init and cleanup */
int major;
unsigned long short_base;
int short_init(void)
{
	int result;

	/*
	 * first, sort out the base/short_base ambiguity: we'd better
	 * use short_base in the code, for clarity, but allow setting
	 * just "base" at load time. Same for "irq".
	 */
	short_base = 0x70;

	/* Get our needed resources. */
		if (! request_region(short_base, 2, "short")) {
			printk(KERN_INFO "short: can't get I/O port address 0x%lx\n",
					short_base);
			return -ENODEV;
		} 

	/* Here we register our device - should not fail thereafter */
	major=MKDEV(252, 0);
	result = register_chrdev(major, "short", &short_fops);
	if (result < 0) {
		printk(KERN_INFO "short: can't get major number\n");
		release_region(short_base,2);  /* FIXME - use-mem case? */
		return result;
	}

	return 0;
}

void short_cleanup(void)
{
	short_base = 0x70;
	unregister_chrdev(major, "short");
	release_region(short_base, 2);
}

module_init(short_init);
module_exit(short_cleanup);
