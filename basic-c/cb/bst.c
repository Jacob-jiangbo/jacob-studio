/*
��tree��һ���������ǿ���������ǿգ���Ӧ����һ�����ڵ�����ɿû��������������ɣ�ÿ������Ҳ������
������binary tree��һ������ÿ���ڵ����ֻ�����������������������ж�����
������ң�������binary search��sorted�� tree��
	�ڹ��������ʱ�����Ǳȸ��ڵ�С�����ݶ����뵽�������У��ȸ��ڵ㲻С�����ݶ����뵽�������У��������в���ʱҲ����ͬ���Ĺ�����������ɵĶ��������Ƕ�����ң�������������ʱ��log2(N)��
����������
v����create������һ�ÿն��������
v����insert�������������в���һ������
v����find���ڶ���������в���һ������
vɾ��erase���ڶ����������ɾ��һ������
v�޸�update���ڶ���������а�һ�����ݸĳ�����һ������
v���clear��������ö��������
v����travel��������ʶ�������������нڵ������
v�Ƿ�Ϊ��empty��
v�ڵ����size��

����һ�ö���������Ļ���˼·��
	����ǿ�����ֱ�Ӳ�����
	���򣬷ֱ������ڵ㲢��������������
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define T int
typedef struct node{
	T data;
	struct node* L;
	struct node* R;
}node;
#define ROOTPTR (*rootptraddr)
#define less(a,b) ((a)<(b))
#define equal(a,b) ((a)==(b))
void create(node** rootptraddr){
	ROOTPTR = NULL;
}
void insertnode(node** rootptraddr, node* p)
{
	if(ROOTPTR==NULL)
		ROOTPTR = p;
	else if(less(p->data,ROOTPTR->data))
		insertnode(&ROOTPTR->L, p);
	else
		insertnode(&ROOTPTR->R, p);
}
void insertdata(node** rootptraddr, T data){
	node* p = malloc(sizeof(node));
	p->data = data;
	p->L = p->R = NULL;
	insertnode(rootptraddr, p);
}
int empty(node* rootptr){
	return rootptr==NULL;
}
int size(node* rootptr)
{
	if(empty(rootptr))
		return 0;
	return size(rootptr->L)+size(rootptr->R)+1;
}
void travel(node* rootptr)
{
	if(rootptr==NULL) return;
	//�����ң�ǰ���ȸ�
	//���Ҹ������򣬺��
	//����ң������и�
	travel(rootptr->L);
	printf("%d ", rootptr->data);
	travel(rootptr->R);	
}
void clear(node** rootptraddr)
{
	if(ROOTPTR==NULL) return;
	clear(&ROOTPTR->L);
	clear(&ROOTPTR->R);
	free(ROOTPTR);
	ROOTPTR = NULL;
}
node** find(node** rootptraddr, T data)
{
	if(ROOTPTR==NULL) return NULL;
	if(equal(ROOTPTR->data,data)) 
		return rootptraddr;
	if(less(data,ROOTPTR->data)) 
		return find(&ROOTPTR->L,data);
	return find(&ROOTPTR->R,data);
}
int erase(node** rootptraddr, T data)
{
	node** pp = find(rootptraddr, data);
	if(pp==NULL) return 0;//����ʧ��
	if((*pp)->L)//����������ǿգ��Ͱ����������ڵ���뵽������
		insertnode(&(*pp)->R, (*pp)->L);
	node* t = (*pp)->R;//����ϲ�����������ĵ�ַ
	free(*pp);//�ͷ�Ҫɾ���Ľڵ�
	*pp = t;//��ԭʼָ��ָ��ϲ����������
	return 1;
}
int update(node** rootptraddr, T olddata, T newdata)
{
	
	if(!erase(rootptraddr, olddata))
		return 0;
	insertdata(rootptraddr, newdata);
	return 1;
}
//Ѱ��
T getrootdata(node* rootptr)
{
	assert(rootptr!=NULL);
	return rootptr->data;
}
int main()
{
	node* rootptr;
	create(&rootptr);
	insertdata(&rootptr, 50);
	insertdata(&rootptr, 20);
	insertdata(&rootptr, 80);
	insertdata(&rootptr, 10);
	insertdata(&rootptr, 30);
	insertdata(&rootptr, 60);
	insertdata(&rootptr, 90);
	travel(rootptr);printf("\n");
	update(&rootptr,30,70); 
	travel(rootptr);printf("\n");
	erase(&rootptr, 60);
	travel(rootptr);printf("\n");
	erase(&rootptr, 50);
	travel(rootptr);printf("\n");
	printf("������:%d, �ڵ���:%d\n", getrootdata(rootptr), size(rootptr));
	clear(&rootptr);
	return 0;
}