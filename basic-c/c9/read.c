/*
	fscanf(FILE*,��ʽ��,...)
	fgetc/getc(FILE*)
	fgets(�ַ����鿪ʼ��ַ���ַ������С��FILE*)
	fread(�����ŵ��ڴ�ʲô�ط�����λ���ȣ����ٸ���λ��FILE*) ���سɹ������ĵ�λ��
	feof(FILE*)����ļ��Ƿ��Ѿ������ˣ��Ѿ���Խ�ļ�ĩβΪ�棬����Ϊ��
	ungetc(�ַ�,FILE*)
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
		printf("��ȡ�ṹ�������ɹ�\n");
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
