#include <stdio.h>

int main(int argc, char* argv[])
{
	printf("argc=%d\n", argc);
	if(argc==1){
		puts("û�д�����");
	}
	else{
		printf("����%d������\n", argc-1);
		int i;
		for(i=1; i<argc; i++)
			printf("����%d:%s\n", i, argv[i]);
	}
	return 0;
}

