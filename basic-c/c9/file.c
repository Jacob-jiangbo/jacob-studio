/*
FILE* fopen(文件路径名，打开方式)
打开方式：
如果咱们要以读文件为主要目的，用r或者r+(允许写文件)，要求文件已经存在，文件不会截断；
如果咱们要以写文件为主要目的，用w或者w+(允许读文件)，如果文件不存在就创建一个新文件，如果已经存在就截断；
如果要以向文件追加内容为主要目的，用a或者a+(允许读文件)，如果文件不存在就创建一个新文件，如果已经存在不会截断，向文件写的内容一律追加在文件末尾
*/
#include <stdio.h>

int main()
{
	char filename[100];
	printf("请输入文件名:");
	scanf("%s", filename);
	FILE* fp = fopen(filename,"r");
	if(fp==NULL){
		printf("文件不存在或者没有读权限\n");
	}
	else{
		printf("打开成功，文件存在\n");
		fclose(fp);
	}
	return 0;
}
