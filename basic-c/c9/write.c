/*
	fprintf(FILE*,��ʽ��,...)
	fputc/putc(�ַ�,FILE*)
	fputs(�ַ���,FILE*)
	fwrite(�ڴ濪ʼ��ַ����λ���ȣ����ٸ���λ��FILE*)
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
		printf("�޷����ļ�file1\n");
		return 1;
	}
	fprintf(f1, "%d %f %c %s\n", 123, 4567.89, '#', "���");
	fputc(',', f1);
	putc('*', f1);
	fputs("��Һò�����ĺ�\n", f1);
	student s={
		"����",
		{1986,7,23},
		{85,96,92,89,97.5}
	};
	fwrite(&s, sizeof(s), 1, f1);
	fflush(f1);//�ѻ������е���������д�������ļ���
	fclose(f1); 
	return 0;
}

