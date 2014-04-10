#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void func(int signo)
{
	if(signo==SIGTERM) printf("������kill\n");
	if(signo==SIGINT) printf("��Ҳ����Ctrl+C\n");
}
int main()
{
	signal(SIGTERM, func);
	signal(SIGINT, func);
	printf("pid=%d\n", getpid());
	for(;;){
		sleep(10);
		printf(".");
		fflush(stdout);
	}
	return 0;
}

