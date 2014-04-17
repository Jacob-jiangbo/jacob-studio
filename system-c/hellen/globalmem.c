#include <linux/init.h>
#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/sched.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <asm/system.h>
#include <asm/uaccess.h>

#define GLOBALMEM_SIZE 0x1000
#define GLOBALMEM_MAJOR 888
#define MEM_CLEAR 0x01

static int globalmem_major = GLOBALMEM_MAJOR;
struct globalmem_dev 
{
	struct cdev cdev;	
	unsigned char mem[GLOBALMEM_SIZE];
};
static struct globalmem_dev * globalmem_devp;

static int globalmem_open(struct inode * inode, struct file * filp)
{
	filp->private_data = globalmem_devp;
	return 0;
}

static int globalmem_release(struct inode * inode, struct file * filp)
{
	return 0;
}

static int globalmem_ioctl(struct inode * inode, struct file * filp, 
						unsigned int cmd, unsigned long arg)
{
	struct globalmem_dev * dev = filp->private_data;
	switch(cmd)
	{	case MEM_CLEAR:
			memset(dev->mem, 0, sizeof(struct globalmem_dev));
			break;
		default:
			return -EINVAL;
	}
	return 0;
}

static ssize_t globalmem_read(struct file * filp, char __user * buf, size_t size, loff_t* opps)
{
	unsigned long p = *opps ;
	unsigned long cnt = size;
//	struct globalmem_dev * dev = filp->private_data;
	globalmem_devp = filp->private_data;
	if(p>=GLOBALMEM_SIZE)
	{	return cnt ? -ENXIO :0;		
	}
	if(cnt > GLOBALMEM_SIZE - p)
	{
		cnt = GLOBALMEM_SIZE - p;
	}
	if(copy_to_user(buf, globalmem_devp->mem+p, cnt))
	{
		return -EFAULT;
	}
	*opps += cnt;	
	return cnt;
}

static ssize_t globalmem_write(struct file * filp, const char __user * buf ,
						      size_t size, loff_t * opps)
{	unsigned long p = *opps;
	unsigned long cnt = size;
	struct globalmem_dev * dev = filp->private_data;
	if( p >= GLOBALMEM_SIZE)
	{
		return cnt? -ENXIO : 0; 
	}	
	if( cnt > GLOBALMEM_SIZE - p)
	{
		cnt = GLOBALMEM_SIZE - p;
	}
	if(copy_from_user(dev->mem+p, buf, cnt))
	{
		return -EFAULT;
	}
	* opps = p + cnt;
	return cnt;
}

static loff_t globalmem_llseek(struct file * filp, loff_t  offset, int orig)
{	loff_t ret = 0;
	switch(orig)
	{
		case 0:
			if(offset<0)
			{
				return  -EINVAL;	
				break;
			}	
			if((unsigned int)offset > GLOBALMEM_SIZE)
			{
				return  -EINVAL;
				break;
			}
			filp->f_pos = (unsigned int)offset;
			ret = filp->f_pos;
			break;
		case 1:
			if((filp->f_pos + offset) > GLOBALMEM_SIZE)	
			{
				ret = -EINVAL;
				break;
			}
			if((filp->f_pos + offset) < 0 )
			{
				ret = -EINVAL;
				break;
			}
			filp->f_pos += offset;
			ret = filp->f_pos;
			break;
		default:
			ret = -EINVAL;
			break;
	}
	return ret;
}

static struct file_operations globalmem_fops = 
{
	.owner = THIS_MODULE,
	.open = globalmem_open,
	.release = globalmem_release,
	.read = globalmem_read,
	.write = globalmem_write,
	.ioctl = globalmem_ioctl,
	.llseek = globalmem_llseek,
};

static void globalmem_setup_cdev(struct globalmem_dev * dev, int index)
{
	int err = 0;
	dev_t devno = MKDEV(globalmem_major, 0);
	cdev_init(&dev->cdev, &globalmem_fops);
	dev->cdev.owner = THIS_MODULE;
	dev->cdev.ops = &globalmem_fops;
	err = cdev_add(&dev->cdev, devno, index); 
	if( err<0 )
		printk(KERN_INFO "cat't cdev_add");
}

static int globalmem_init(void)
{
	int result = 0;
	dev_t devno = MKDEV(globalmem_major, 0);
	if(globalmem_major)
		result = register_chrdev_region(devno, 1, "globalmem");
	else
	{
		result = alloc_chrdev_region(&devno, 0, 1, "globalmem");
		globalmem_major = MAJOR(devno);
	}
	if(result < 0)
	{
		printk(KERN_INFO "can't register\n");
		return result;
	}
	globalmem_devp = kmalloc(sizeof(struct globalmem_dev), GFP_KERNEL);
	if(!globalmem_devp)
	{
		goto fail_malloc;
	}
	memset(globalmem_devp, 0, sizeof(struct globalmem_dev));
	globalmem_setup_cdev(globalmem_devp, 1);
	return 0;
	fail_malloc: unregister_chrdev_region(devno, 1);
	return result;
}	

static void globalmem_exit(void)
{
	dev_t devno = MKDEV(globalmem_major, 0);
	cdev_del(&globalmem_devp->cdev);
	kfree(globalmem_devp);
	unregister_chrdev_region(devno, 1);
}

MODULE_LICENSE("Dual BSD/GPL");
module_init(globalmem_init);
module_exit(globalmem_exit);

