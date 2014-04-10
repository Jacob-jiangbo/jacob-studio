#include <stdio.h>
#include <stdlib.h>
/*
void qsort(��ʼ��ַ��Ԫ�ظ�����Ԫ�صĵ�λ���ȣ��ȽϺ���)
�ȽϺ�����
int ������(const void* a, const void* b)
a��b�ֱ�������Ԫ�صĵ�ַ��
���Ԫ��˳����Ҫ������Ҫ���ظ�����
���Ԫ��˳����Ҫ������Ҫ����������
��������������ν��Ҫ����0��
*/
typedef struct student{
	char name[20];
	int age;
	double score;
}student, *stuptr;

void input(student a[], int n)
{
	int i;
	for(i=0; i<n; i++){
		printf("�������%d��ѧ��������������ͳɼ�:",i+1);
		scanf("%s%d%lf",&a[i].name,&a[i].age,&a[i].score);
	}
}
void print(stuptr a, int n)
{//a->name == (*a).name == a[0].name
	int i;
	for(i=0; i<n; i++,a++)
		printf("%s:\t%d\t%g\n", a->name,a->age,a->score);
}
int nameasc(const void* a, const void* b)
{
	stuptr p=(student*)a, q=(stuptr)b;
	return strcmp(p->name,q->name);
}
int scoredsc(const void* a, const void* b)
{
	stuptr p=(stuptr)a, q=(stuptr)b;
	if(p->score > q->score) return -1;
	if(p->score < q->score) return 1;
	return 0;
}
int main()
{
	printf("������ѧ������:");
	int n;
	scanf("%d", &n);
	stuptr /*const*/ p = calloc(n, sizeof(student));
	if(p==NULL){
		printf("�����ڴ�ռ�ʧ��!\n");
		return 1;
	}
	input(p, n);
	qsort(p, n, sizeof(student), nameasc);
	print(p, n);
	qsort(p, n, sizeof(student), scoredsc);
	print(p, n);
	//p++;free(p-1);
	free(p); p=NULL;//*(stuptr*)&p=NULL;printf("%p\n",p);
	return 0;
}
