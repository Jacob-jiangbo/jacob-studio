#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[])
{
	if(argc==1){
		printf("用法:\n\t%s 人名 ...\n", argv[0]);
		return 0;
	}
	if(strcmp(argv[0],"thanks")!=0){
		printf("请使用正版软件!\n");
		remove(argv[0]);
		return 0;
	}
	int i;
	for(i=1; i<argc; i++)
		printf("感谢你，%s！\n", argv[i]);
	return 0;
}
