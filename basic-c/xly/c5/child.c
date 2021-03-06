#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
/*
waitpid(子进程pid，用来保存结束状态的变量的地址，0或者WNOHANG)
用来回收指定pid子进程资源，pid为-1表示不指定子进程pid。
0表示函数等待子进程结束才返回，返回值为结束的子进程pid
WNOHANG表示函数不等待，如果子进程结束了就返回子进程pid，没有子进程结束就返回0。
出错返回-1。
*/
int main()
{
	int i=0;
	int ret = fork();
	if(ret==0)
	{//子进程满足这个条件
		for(i=0; i<5; i++){
			printf("i=%d, ret=%d, 我的进程id%d,老爸%d\n", 
				i, ret,	getpid(),getppid());
			sleep(1);
		}
	}
	else
	{//父进程，也就是原来那个进程
		for(i=50; i<65; i++)
		{
			printf("ret=%d,我是父进程%d\n", ret,getpid());
			sleep(1);
			printf("*****%d*****\n",waitpid(-1, NULL, WNOHANG));
		}
	}
	return 0;
}

