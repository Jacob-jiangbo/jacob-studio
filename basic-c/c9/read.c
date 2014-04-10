/*
	fscanf(FILE*,格式串,...)
	fgetc/getc(FILE*)
	fgets(字符数组开始地址，字符数组大小，FILE*)
	fread(读来放到内存什么地方，单位长度，多少个单位，FILE*) 返回成功读到的单位数
	feof(FILE*)检测文件是否已经读完了，已经超越文件末尾为真，否则为假
	ungetc(字符,FILE*)
*/
#include <stdio.h>
typedef struct student{
	char name[20];
	int date[3];
	double score[5];
}student;

int main()
{
	FILE* f2 = fopen("file2", "r");
	if(NULL==f2){
		
		perror("open");
		return 1;
	}
	int n;
	double d;
	char c;
	char str[100];
	char c1, c2, c3;
	student m;
	fscanf(f2, "%d%lf %c%s", &n, &d, &c, str);
	fscanf(f2, " %c", &c1);
	ungetc(c1, f2);
	c2 = fgetc(f2);
	c3 = getc(f2);
	char line[100];
	fgets(line, sizeof(line), f2);
	if(fread(&m, sizeof(m), 1, f2)!=1){
		printf("读取结构变量不成功\n");
	}
	printf("feof? %d\n", feof(f2));
	fgetc(f2);
	printf("feof? %d\n", feof(f2));
	fclose(f2);
	printf("n=%d, d=%g, c=%c, str=%s\n",n,d,c,str);
	printf("c1=%c, c2=%c, c3=%c\n", c1, c2, c3);
	printf("%s", line);
	printf("%s:%d-%d-%d\n", m.name,m.date[0],m.date[1],m.date[2]);
	int i;
	for(i=0; i<5; i++)
		printf("%g ", m.score[i]);
	printf("\n");
	return 0;
}
