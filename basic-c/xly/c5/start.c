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
	pid = fork();
	if(pid==0)
	{
		close(fd);
		for(;;)
		{
			printf("a");
			fflush(stdout);
			sleep(1);
		}
	}
	else 
	{
		write(fd, &pid, sizeof(pid));
		if((pid=fork())==0)
		{
			close(fd);
			for(;;)
			{
				printf("b");
				fflush(stdout);
				sleep(1);
			}
		}
		else{
			write(fd, &pid, sizeof(pid));
			if((pid=fork())==0)
			{
				close(fd);
				for(;;)
				{
					printf("c");
					fflush(stdout);
					sleep(1);
					printf("pid = %d\n", getpid());
				}
			}
			else
			{
				close(fd);
			}
		}
	}
	return 0;
}

