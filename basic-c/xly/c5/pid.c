#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("进程id:%d\n", getpid());
	printf("父进程id:%d\n", getppid());
	pause();
	return 0;
}

