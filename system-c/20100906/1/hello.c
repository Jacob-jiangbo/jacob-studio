/*                                                     
 * $Id: hello.c,v 1.5 2004/10/26 03:32:21 corbet Exp $ �����ñ�׼c����д 
 */                                                    
#include <linux/init.h>
#include <linux/module.h>
#include <asm/current.h>

MODULE_LICENSE("Dual BSD/GPL");//ָ����ȨЭ��

static int hello_init(void)//����һ�㶼��д xx_init 
{
	int count;
	printk(KERN_ALERT "Hello, world\n");//printk �ں˵����������printf
	printk("<1>Hello,world\n");
	for(count=0;count<5;count++)
	{
		printk("<1>count=%d\n",count);
	}
//	printk("<1>pid = %d\n",current->pid);
//	printk("<1>name=%s\npid=%d\n",current->comm,current->pid);//��Ҫ��ס
	return 0;
}

static void hello_exit(void)//ж��void__exit
{
	printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(hello_init);//ģ�����ʱִ���ĸ������������Ǿ�̬������
module_exit(hello_exit);//������ж��ʱִ���ĸ�����

