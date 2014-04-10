#include <stdio.h>
#include <unistd.h>

int main()
{
	int i;
	if(fork()==0){
		for(i=0; i<1; i++)
		printf("我是a，我的进程id%d，父进程%d\n", getpid(), getppid());
	}
	else if(fork()==0){
		for(i=0; i<1; i++)
		printf("我是b，我的进程id%d，父进程%d\n", getpid(), getppid());
	}
	else if(fork()==0){
		for(i=0; i<1; i++)
		printf("我是c，我的进程id%d，父进程%d\n", getpid(), getppid());
	}
	else {
		for(i=0; i<1; i++)
		printf("我是父进程%d\n", getpid());
	}
	return 0;
}

\n", getpid(), getppid());
	}
	else if(fork()==0){
		for(i=0; i<5; i++,sleep(1))
		printf("我是c，我的进程id%d，父进程%d\n", getpid(), getppid());
	}
	else {
		for(i=0; i<20; i++,sleep(1))
		printf("我是父进程%d\n", getpid());
	}
	return 0;
}

