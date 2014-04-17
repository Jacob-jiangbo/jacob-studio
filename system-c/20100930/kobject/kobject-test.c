#include <linux/device.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/string.h>
#include <linux/sysfs.h>
#include <linux/stat.h>
#include <linux/kobject.h>
MODULE_LICENSE("Dual BSD/GPL");
 
struct kobject *kobj;
struct kobject *testkobj;
char *name;
 
void obj_test_release(struct kobject *kobject);

/* 拷贝attr内容到buf，buf大小为PAGE_SIZE */
ssize_t test_show(struct kobject * kobject,struct attribute * attr,char * buf)
{
	printk("have show .\n");
	printk("attrname:%s .\n",attr->name);
	sprintf(buf,"%s\n",attr->name);
	return strlen(attr->name)+2;
}

/* 拷贝buf内容到attr，buf大小为PAGE_SIZE */
ssize_t test_store(struct kobject * kobject,struct attribute * attr,char * buf,size_t count)
{
	printk("havwstore\n");
	kfree(name);
	name = kmalloc(count,GFP_KERNEL);
	if(!name) {
		printk("kmalloc error\n");
		return ENOMEM;
	}
	for(;*buf !='\0';buf++) {
		*(name)++ = *buf;
	}
	*(name) = '\0';
	name = name - count;
	attr->name = name;
	printk("write: %s\n",attr->name);
	return count;
}

/*
  映射在sysfs的文件
*/
struct attribute test_attr ={
	.name = "kobjecttest",
	/* S_IRUGO=所有人可读；S_IWUGO=所有人可写；
	S_IRUSR=所有者可读；S_IWUSR=所有者可写；
	S_IRUGO|S_IWUSR=所有人可读且所有者可写 */
	.mode = S_IRWXUGO,
};

static struct attribute *def_attrs[] ={
	&test_attr,
	NULL
};

struct sysfs_ops obj_test_sysops ={
	.show = test_show,
	.store = test_store
};

struct kobj_type ktype = {
	.release = obj_test_release,
	.sysfs_ops = &obj_test_sysops,
	.default_attrs= def_attrs
};

void obj_test_release(struct kobject * kobject)
{
	printk("<1>kobject_test: release .\n");
}

static int kobject_test_init()
{
	printk("<1>kobject test init.\n");
	kobj = kmalloc(sizeof(struct kobject),GFP_KERNEL);
	testkobj= kmalloc(sizeof(struct kobject),GFP_KERNEL);
	name = kmalloc(0,GFP_KERNEL);
	if(!kobj) {
		printk("<1>kmalloc error\n");
		return ENOMEM;
	}
	memset(kobj,0,sizeof(struct kobject));
	memset(testkobj,0,sizeof(struct kobject));

	kobject_init_and_add(kobj,&ktype,NULL,"kobjecttest");
	kobject_init_and_add(testkobj,&ktype,kobj,"hlp");
 
	return 0;
}

static void kobject_test_exit()
{
	printk("<1>kobject test exit.\n");
	kobject_del(kobj);
	kfree(kobj);
	kfree(testkobj);
	kfree(name);
}

module_init(kobject_test_init);
module_exit(kobject_test_exit);

