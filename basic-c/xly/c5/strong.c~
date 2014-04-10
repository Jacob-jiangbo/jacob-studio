#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void func(int signo)
{
	if(signo==SIGTERM) printf("°³²»ÅÂkill\n");
	if(signo==SIGINT) printf("°³Ò²²»ÅÂCtrl+C\n");
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

