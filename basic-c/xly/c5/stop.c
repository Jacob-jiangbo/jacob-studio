#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>

int main()
{
	int pid;
	int fd=open("pids", O_RDONLY);
	if(fd<0) return 0;
	while(read(fd, &pid, sizeof(pid))>0)
		kill(pid, SIGKILL);
	close(fd);
	remove("pids");
	return 0;
}

