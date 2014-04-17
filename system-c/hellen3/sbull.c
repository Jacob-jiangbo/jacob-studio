#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kdev_t.h>

#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/errno.h>
#include <linux/poll.h>
#include <linux/slab.h>
#include <linux/time.h>
#include <linux/interrupt.h>
#include <linux/blkdev.h>
#include <linux/types.h>
#include <linux/fcntl.h>
#include <linux/genhd.h>
#include <linux/buffer_head.h>
#include <linux/bio.h>

#include <linux/fs.h>
#include <linux/vmalloc.h>

MODULE_LICENSE("Dual BSD/GPL");

static int major = 0;
module_param(major, int, 0);
static int hardsect_size = 512;
module_param(hardsect_size, int, 0);
static int nsectors = 1024;
module_param(nsectors, int, 0);
static int ndevices = 4;
module_param(ndevices, int, 0);

enum
{
	RM_SIMPLE	= 0,
	RM_FULL 	= 1,
	RM_NOQUEUE	= 2,
}; 
static int request_mode = RM_SIMPLE;
module_param(request_mode, int, 0);

#define KERNEL_SECTOR_SIZE 512

struct sbull_dev
{
	int size;
	u8 * data;
	short users;
	short media_change;
	spinlock_t lock;
	struct request_queue * queue;
	struct gendisk * gd;
	struct time_list timer;
};

static struct sbull_dev * Device;

static void sbull_transfer(struct sbulll_dev * dev, unsigned long sector, 
						unsigned long nsect, char * buffer, int write)
{
	unsigned long offset = sector * KERNEL_SECTOR_SIZE;	
	unsigned long nbytes = nsect * KERNEL_SECOTOR_SIZE;
	
	if(offsetn + nbytes > dev->size)
	{
		printk(KERN_INFO "beyand end write");
		return;
	}
	if(write)
		memcpy(dev->data + offset, buffer, nbytes);
	else
		memcpy(buffer, dev->data + offset, nbytes);
}

static void sbull_request(request_queue_t * q)
{
	struct request * req;
	which((req = elv_next_request(q)) != NULL)
	{
		struct sbull_dev * dev = req->rq_disk->private_data;
		if( ! blk_fs_request(req))
		{
			printk(KERN_INFO "Skip non_fs request\n");
			end_request(req, 0);
			continue;
		}
		sbull_transfer(dev, req->sector, req->current_nr_sectors,
						req->buffer, rq->data->dir(req));
		end_request(req, 1);
	}



}

static void setup_device(struct sbull_dev * dev, int which)
{
	memset(dev, 0, sizeof(struct sbull_dev));
	dev->size = nsectors * hardsect_size;
	dev->data = vmalloc(dev->size);
	if(NULL == dev->data)
	{
		printk(KERN_NOTICE "vmalloc failure.\n");
		return;
	}
	spin_lock_init(&dev->lock);
	
	init_timer(&dev->timer);
	dev->timer.data = (unsigned long)dev;
	dev->timer.function = sbull_invalitate;

	switch(request_mode)
	{
		default:
			printk(KERN_INFO "unknow cmd!\n");
			break;
		case RM_SIMPLE:
			dev->queue = blk_init_queue(sbull_request, &dev->lock);
			if(NULL == dev->queue)
				goto out_vfree;
			break;
	}
	blk_queue_hardsect_size(dev->queue, hardsize_size);
	dev->queue->queuedata = dev;
	
	dev->gd = alloc_malloc(SBULL_MINORS);	
	if( !dev->gd )
	{
		printk(KERN_INFO "alloc_disk failure");	
		goto out_vfree;
	}
	dev->gd->major = sbull_major;
	dev->gd->first_minor = which * SBULL_MINORS;
	dev->gd->fops = &sbull_ops;
	dev->gd->queue = dev->queue;
	dev->gd->private_data = dev;
	snprintf(dev->gd->disk_name, 32, "sbull%c", which + 'a');
	set_capacity(dev->gd, nsectors * (hardsect_size/KERNEL_SECTOR_SIZE));
	add_disk(dev->gd);
	return;
out_vfree:
	if(dev->data)
		vfree(dev->data);
}

static int __init sbull_init(void)
{	int result;
	int i;
	sbull_major = register_blkdev(sbull_major, "sbull");
	if(sbull_major <= 0)
	{
		printk(KERN_WARNING "sbull: can't get major number\n");	
		return -EBUSY;
	}
	Device = kmalloc(ndevices*sizeof(struct sbull_dev), GFP_KERNEL);
	if(NULL == Device)
		goto out_unregister;
	for(i = 0; i< ndevices; i++)
		setup_device(Device + i, i);

	return 0;

out_unregister: 
	unregister_blkdev(sbull_major, "sbd");
	return -ENOMEM;

}

static void __exit sbull_exit(void)
{
	




}

module_init(sbull_init);
module_exit(sbull_exit);
