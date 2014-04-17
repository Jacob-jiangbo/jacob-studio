/*                                                     
 * $Id: hello.c,v 1.5 2004/10/26 03:32:21 corbet Exp $ 不能用标准c程序写 
 */                                                    
#include <linux/init.h>
#include <linux/module.h>
#include <asm/current.h>

MODULE_LICENSE("Dual BSD/GPL");//指明版权协议

static int hello_init(void)//加载一般都会写 xx_init 
{
	int count;
	printk(KERN_ALERT "Hello, world\n");//printk 内核的输出不能用printf
	printk("<1>Hello,world\n");
	for(count=0;count<5;count++)
	{
		printk("<1>count=%d\n",count);
	}
//	printk("<1>pid = %d\n",current->pid);
//	printk("<1>name=%s\npid=%d\n",current->comm,current->pid);//需要记住
	return 0;
}

static void hello_exit(void)//卸载void__exit
{
	printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(hello_init);//模块加载时执行哪个函数（必须是静态函数）
module_exit(hello_exit);//函数被卸载时执行哪个函数

