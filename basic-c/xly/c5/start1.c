#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int pid;
	int fd = open("pids", O_WRONLY|O_CREAT|O_APPEND, 0600);
	if(fd<0)
	{
		printf("无法打开文件pids\n");
		return 1;
	}
	if(fork()==0)
	{
		pid = getpid();
		write(fd, &pid, sizeof(pid));
		close(fd);
		for(;;)
		{
			printf("a");
			fflush(stdout);
			sleep(1);
		}
	}
	else if(fork()==0)
	{
		pid = getpid();
		write(fd, &pid, sizeof(pid));
		close(fd);
		for(;;)
		{
			printf("b");
			fflush(stdout);
			sleep(1);
		}
	}
	else if(fork()==0){
		pid = getpid();
		write(fd, &pid, sizeof(pid));
		close(fd);
		for(;;){
			printf("c");
			fflush(stdout);
			sleep(1);
		}
	}
	else{
		close(fd);
	}
	return 0;
}

