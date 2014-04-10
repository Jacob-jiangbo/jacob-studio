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
�Ƿ���full���ж϶����Ƿ�������һ�������ǰ�ж�
*/
#define T int
typedef struct node{//�ڵ�ṹ
	T data;
	struct node* next;
}node;
typedef struct queue{//���нṹ
	node* headptr;//ָ���һ���ڵ�
	node* tailptr;//ָ�����һ���ڵ�
	int len;
}queue;

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//����һ���ն���
void create(queue* p)
{
	//memset(p, 0, sizeof(queue));���������������������
	p->headptr = NULL;
	p->tailptr = NULL;
	p->len = 0;
}
//���
void push(queue* p, T data)
{
	//׼���ڵ�
	node* t = (node*)malloc(sizeof(node));
	//if(t==NULL) {...}
	t->data = data;
	t->next = NULL;
	//���½ڵ�ҽ���ԭ����β�ڵ�֮��
	if(p->tailptr)
		p->tailptr->next = t;
	//��βָ��ָ���µ�β�ڵ�
	p->tailptr = t;
	//�������ԭ��Ϊ�գ��½ڵ�Ҳ�ǵ�һ���ڵ�
	if(p->headptr==NULL)
		p->headptr = p->tailptr;
	//�ڵ��������
	p->len++;
}
//ȡ��Ԫ�ظ���
int size(const queue* p)
{
	return p->len;
}
//�ж��Ƿ�Ϊ��
int empty(const queue* p)
{
	return p->headptr==NULL;
}
//���ӣ�ɾ������Ԫ��
void pop(queue* p)
{
	if(empty(p)) return;
	node* t = p->headptr->next;
	free(p->headptr);
	p->headptr = t;
	--p->len;
	if(empty(p))
		p->tailptr = NULL;
}
//����
T front(const queue* p)
{
	assert(!empty(p));
	return p->headptr->data;
}
//��β
T back(const queue* p)
{
	assert(!empty(p));
	return p->tailptr->data;
}
//��ն���
void clear(queue* p)
{
	node* pn = p->headptr;
	while(pn!=NULL){
		node* t = pn->next;
		free(pn);
		pn = t;
	}
	p->headptr = p->tailptr = NULL;
	p->len = 0;
}
int main()
{
	queue q;
	create(&q);
	push(&q,10);push(&q,20);push(&q,30);push(&q,40);
	while(!empty(&q)){
		printf("%d\n", front(&q));
		pop(&q);
	}
	push(&q,50);push(&q,60);push(&q,70);push(&q,80);
	printf("front:%d, back:%d\n", front(&q), back(&q));
	clear(&q);
	return 0;
}
