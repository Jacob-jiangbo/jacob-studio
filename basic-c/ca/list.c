#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//�ڵ�(node)
typedef int T;
#define visitdata(data) printf("%d ",data)
#define equal(a,b) ((a)==(b))

typedef struct node{
	T data;
	struct node* next;
}node;
//һ�����ɸ��ڵ㴮��һ���������(linked list)
//����һ������ֻҪ֪����һ���ڵ㣨ͷ�ڵ㣩������Ϳ�����
typedef node* list;
/*
����Ӧ�þ߱��Ĳ�����
v����������
v��������
vɾ������
v��������
v��������
v�޸�����
v�ͷ�����
vȡ�ó���
v�Ƿ�Ϊ��
vȡͷ����
vȡβ����
*/
//����������
void createlist(node** pptr)
{
	*pptr = NULL;
}
//ȡ�ó���
int listsize(node* p)
{
	int cnt=0;
	while(p!=NULL){
		++cnt;
		p = p->next;
	}
	return cnt;
}
//��������
void travel(node* p)
{
	while(p!=NULL){
		visitdata(p->data);
		p = p->next;
	}
	printf("\n");
}
//�Ƿ�Ϊ������
int empty(node* p)
{
	return p==NULL;
}
//ȡ�������б��Ϊindex��ԭʼָ��ĵ�ַ���Ա���������ܷ���ԭʼָ��
node** getptraddr(node** headptraddr, int index)
{
	int len = listsize(*headptraddr);
	if(index<0||index>len){
		fprintf(stderr,"��Чָ����%d\n",index);
		index = len;//exit(1);
	}
	if(index==0)
		return headptraddr;//headptr�ĵ�ַ
	node* p = *headptraddr;//�ѵ�һ���ڵ�ĵ�ַ������p��
	int i;
	for(i=1; i<index; i++)
		p = p->next; 
	return &(p->next);
}
void insert(node** headptraddr, T data, int index)
{
	//ptraddr������Ϊindex��ԭʼָ��ĵ�ַ
	node** ptraddr = getptraddr(headptraddr, index);
	//׼���ڵ㱣��������
	node* p = malloc(sizeof(node));
	if(p==NULL) return;
	p->data = data;
	//���½ڵ���뵽ԭʼָ�����
	p->next = *ptraddr;//��ԭʼָ�루Ҳ������һ���ڵ��ַ�����½ڵ��next��Ա
	*ptraddr = p;//��ԭʼָ��ָ���½ڵ�
}
void pushfront(node** headptraddr, T data){
	insert(headptraddr,data,0);
}
void pushback(node** headptraddr, T data){
	insert(headptraddr,data,listsize(*headptraddr));
}
//�ͷ�����
void clear(node** headptraddr)
{//headptraddr��headptr�ĵ�ַ
/*	node* p = *headptraddr;
	while(p!=NULL){
		node* q = p->next;
		free(p);
		p = q;
	}
	*headptraddr = NULL;
*/
	while(*headptraddr!=NULL){//*headptraddr����headptr����һ���ڵ�ĵ�ַ
		node* p = (*headptraddr)->next;//��һ���ڵ��next��Ա���ڶ����ĵ�ַ
		free(*headptraddr);
		*headptraddr = p;
	}
}
T frontdata(node* headptr)
{
	assert(headptr!=NULL); 
	return headptr->data; 
}
T backdata(node* headptr)
{
	assert(headptr!=NULL);
	node* p = headptr;
	while(p->next!=NULL)
		p = p->next;
	return p->data; 
}
//ɾ�������е�n������
void erase(node** headptraddr, int n)
{
	node** ptraddr = getptraddr(headptraddr, n-1);//ȡ��ԭʼָ��ĵ�ַ
	if(*ptraddr==NULL){
		fprintf(stderr, "��Ч�Ľڵ����%d!\n", n);
		return;
	}
	node* p = *ptraddr;//��ԭʼָ�����һ��
	*ptraddr = p->next; //������ڵ��next��Ա����һ���ڵ�ĵ�ַ����ֵ��ԭʼָ��
	free(p);
}
//�������ݣ������������ڵĽڵ���ţ��ڼ����ڵ㣩
int find(node* headptr, T data)
{
	node* p = headptr;
	int n=1;
	while(p!=NULL){
		if(equal(p->data,data))
			return n;
		p = p->next;
		++n;
	}
	return 0;
}
void setdata(node* headptr, int n, T val)
{
	node** ptraddr = getptraddr(&headptr, n-1);
	if(*ptraddr==NULL)//��Ч�ڵ����n
		return;
	(*ptraddr)->data = val;
}
int main()
{
	node* headptr;//�����һ���ڵ�ĵ�ַ
	createlist(&headptr);
	insert(&headptr, 10, 2);//��Чλ�ã��������ĩβ
	insert(&headptr, 20, 0);//20,10
	insert(&headptr, 30, 2);//20,10,30
	insert(&headptr, 40, 1);//20,40,10,30
	insert(&headptr, 50, 8);//��Чλ�ã��������ĩβ
	travel(headptr);
	printf("ʣ��%d������\n", listsize(headptr));
	int n = find(headptr, 10);
	printf("����10�ڵ�%d���ڵ�\n", n);
	erase(&headptr, n);
	travel(headptr);
	n = find(headptr, 10);
	printf("����10�ڵ�%d���ڵ�\n", n);
	erase(&headptr, n);
	travel(headptr);
	setdata(headptr, 10, 100);
	setdata(headptr, 2, 99);
	travel(headptr);
	clear(&headptr);
	printf("ʣ��%d������\n", listsize(headptr));
	return 0;
}
