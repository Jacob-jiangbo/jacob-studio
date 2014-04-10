/*
����queue��һ���������Ա������ɾ�������ڲ�ͬ�ˡ�
����������
v����create����һ���ն��У���ЧԪ�ظ���Ϊ0��
v���clear���Ѷ��б�ɿն��У�����������ЧԪ�أ�
v����front��ȡ��������ӵ��Ǹ�Ԫ�أ�
v��βback��ȡ�������ӵ��Ǹ�Ԫ�أ�
v���push����һ��Ԫ�ؼ��뵽�����г�Ϊ�µĶ�β��
v����pop���Ѷ���Ԫ�شӶ�����ɾ��������������
v��ЧԪ�ظ���size��ȡ�ö�������ЧԪ�ظ�����
v�Ƿ�Ϊ��empty���ж϶����Ƿ��ǿգ�һ���ڳ��Ӻ�ȡ��β֮ǰ�ж�
v�Ƿ���full���ж϶����Ƿ�������һ�������ǰ�ж�
*/
#define T int
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct queue{
	T *a;
	int capacity;
	int len;
	int head;
}queue;
//����ָ�������Ŀն��У����سɹ����
int create(queue* p, int capacity)
{
	p->a = calloc(capacity, sizeof(T));
	if(p->a==NULL) 
		return 0;
	p->capacity = capacity;
	p->len = 0;
	p->head = 0;
}
//���
void push(queue* p, T data)
{
	assert(!full(p));
	p->a[(p->head+p->len++)%p->capacity] = data;
}
//ȡ��Ԫ�ظ���
int size(const queue* p)
{
	return p->len;
}
//�Ƿ���
int full(const queue* p)
{
	return p->len==p->capacity;
}
//�Ƿ��
int empty(const queue* p)
{
	return p->len==0;
}
//����
T front(const queue* p)
{
	assert(!empty(p));
	return p->a[p->head];
}
//����
void pop(queue* p)
{
	assert(!empty(p));
	p->head = (p->head+1)%p->capacity;
	p->len--;
}
//��β
T back(const queue* p)
{
	return p->a[(p->head+p->len-1)%p->capacity];
}
//���
void clear(queue* p)
{
	p->len = 0;
}
//�ͷ�
void release(queue* p)
{
	free(p->a);
	p->a = NULL;
	p->head = 0;
	p->len = 0;
	p->capacity = 0;
}
//��������չʾ
void show(const queue* p)
{
	int i;
	printf("%d/%d:", p->len, p->capacity);
	for(i=0; i<p->len; i++)
		printf("%d ",p->a[(p->head+i)%p->capacity]);
	printf("\n");
}
int main()
{
	queue q;
	create(&q, 5);
	char cmd;
	T data;
	for(;;){
		printf("i data/o/c/q:");
		scanf(" %c", &cmd);
		if(cmd=='q') break;
		if(cmd=='i'){
			scanf("%d", &data);
			push(&q, data);
			show(&q);
		}
		if(cmd=='o'){
			printf("%d\n", front(&q));
			pop(&q);
			show(&q);
		}
		if(cmd=='c') clear(&q);
	}
	release(&q);
}
