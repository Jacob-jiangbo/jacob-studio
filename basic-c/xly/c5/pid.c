#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("����id:%d\n", getpid());
	printf("������id:%d\n", getppid());
	pause();
	return 0;
}

