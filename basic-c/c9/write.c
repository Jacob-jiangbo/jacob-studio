/*
	fprintf(FILE*,格式串,...)
	fputc/putc(字符,FILE*)
	fputs(字符串,FILE*)
	fwrite(内存开始地址，单位长度，多少个单位，FILE*)
*/
#include <stdio.h>

typedef struct student{
	char name[20];
	int date[3];
	double score[5];
}student;
int main()
{
	FILE* f1 = fopen("file1", "wb");
	if(f1==NULL){
		printf("无法打开文件file1\n");
		return 1;
	}
	fprintf(f1, "%d %f %c %s\n", 123, 4567.89, '#', "你好");
	fputc(',', f1);
	putc('*', f1);
	fputs("大家好才是真的好\n", f1);
	student s={
		"马春花",
		{1986,7,23},
		{85,96,92,89,97.5}
	};
	fwrite(&s, sizeof(s), 1, f1);
	fflush(f1);//把缓冲区中的内容真正写到磁盘文件中
	fclose(f1); 
	return 0;
}

