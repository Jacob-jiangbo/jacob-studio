#include <stdio.h>

int main(int argc, char* argv[])
{
	printf("argc=%d\n", argc);
	if(argc==1){
		puts("没有带参数");
	}
	else{
		printf("带了%d个参数\n", argc-1);
		int i;
		for(i=1; i<argc; i++)
			printf("参数%d:%s\n", i, argv[i]);
	}
	return 0;
}

