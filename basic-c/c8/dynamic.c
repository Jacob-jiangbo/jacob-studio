/*
void* malloc(�ֽ���),�ɹ�����������ڴ濪ʼ��ַ��ʧ�ܷ���NULL
void free(��ַ),�ͷ��ڴ�ռ䣬�����Ƕ�̬������ڴ�ռ�ĵ�ַ

void*calloc(Ԫ�ظ�����ÿ��Ԫ�ص��ֽ���),Ϊ��������ռ䣬������
void*realloc(�ɶ�̬�ڴ��ַ�����ֽ���),�ͷžɿռ䣬�����¿ռ䣬��Ѿɿռ��е����ݸ��Ƶ��¿ռ���
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* p1 = (int*)malloc(sizeof(int));
	*p1 = 100;
	int* p2 = calloc(10, sizeof(int));
	if(NULL==p2){
		return 1;
	}
	int i;
	for(i=0; i<10; i++)
		p2[i] = 50+i;
	p2 = realloc(p2, 15*sizeof(int));
	printf("*p1=%d\n", *p1);
	for(i=0; i<15; i++)
		printf("%d ", p2[i]);
	printf("\n");
	free(p1); p1=NULL;
	free(p2); p2=NULL;
	return 0;
}
