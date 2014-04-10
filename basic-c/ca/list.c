#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//节点(node)
typedef int T;
#define visitdata(data) printf("%d ",data)
#define equal(a,b) ((a)==(b))

typedef struct node{
	T data;
	struct node* next;
}node;
//一串若干个节点串在一起就是链表(linked list)
//管理一个链表，只要知道第一个节点（头节点）在哪里就可以了
typedef node* list;
/*
链表应该具备的操作：
v创建空链表
v插入数据
v删除数据
v查找数据
v遍历数据
v修改数据
v释放链表
v取得长度
v是否为空
v取头数据
v取尾数据
*/
//创建空链表
void createlist(node** pptr)
{
	*pptr = NULL;
}
//取得长度
int listsize(node* p)
{
	int cnt=0;
	while(p!=NULL){
		++cnt;
		p = p->next;
	}
	return cnt;
}
//遍历数据
void travel(node* p)
{
	while(p!=NULL){
		visitdata(p->data);
		p = p->next;
	}
	printf("\n");
}
//是否为空链表
int empty(node* p)
{
	return p==NULL;
}
//取得链表中编号为index的原始指针的地址，以便后续操作能访问原始指针
node** getptraddr(node** headptraddr, int index)
{
	int len = listsize(*headptraddr);
	if(index<0||index>len){
		fprintf(stderr,"无效指针编号%d\n",index);
		index = len;//exit(1);
	}
	if(index==0)
		return headptraddr;//headptr的地址
	node* p = *headptraddr;//把第一个节点的地址保存在p中
	int i;
	for(i=1; i<index; i++)
		p = p->next; 
	return &(p->next);
}
void insert(node** headptraddr, T data, int index)
{
	//ptraddr保存编号为index的原始指针的地址
	node** ptraddr = getptraddr(headptraddr, index);
	//准备节点保存新数据
	node* p = malloc(sizeof(node));
	if(p==NULL) return;
	p->data = data;
	//把新节点插入到原始指针后面
	p->next = *ptraddr;//把原始指针（也就是下一个节点地址）给新节点的next成员
	*ptraddr = p;//让原始指针指向新节点
}
void pushfront(node** headptraddr, T data){
	insert(headptraddr,data,0);
}
void pushback(node** headptraddr, T data){
	insert(headptraddr,data,listsize(*headptraddr));
}
//释放链表
void clear(node** headptraddr)
{//headptraddr是headptr的地址
/*	node* p = *headptraddr;
	while(p!=NULL){
		node* q = p->next;
		free(p);
		p = q;
	}
	*headptraddr = NULL;
*/
	while(*headptraddr!=NULL){//*headptraddr就是headptr，第一个节点的地址
		node* p = (*headptraddr)->next;//第一个节点的next成员，第二个的地址
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
//删除链表中第n个数据
void erase(node** headptraddr, int n)
{
	node** ptraddr = getptraddr(headptraddr, n-1);//取得原始指针的地址
	if(*ptraddr==NULL){
		fprintf(stderr, "无效的节点序号%d!\n", n);
		return;
	}
	node* p = *ptraddr;//把原始指针另存一份
	*ptraddr = p->next; //把这个节点的next成员（下一个节点的地址）赋值给原始指针
	free(p);
}
//查找数据，返回数据所在的节点序号（第几个节点）
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
	if(*ptraddr==NULL)//无效节点序号n
		return;
	(*ptraddr)->data = val;
}
int main()
{
	node* headptr;//保存第一个节点的地址
	createlist(&headptr);
	insert(&headptr, 10, 2);//无效位置，会更正成末尾
	insert(&headptr, 20, 0);//20,10
	insert(&headptr, 30, 2);//20,10,30
	insert(&headptr, 40, 1);//20,40,10,30
	insert(&headptr, 50, 8);//无效位置，会更正成末尾
	travel(headptr);
	printf("剩余%d个数据\n", listsize(headptr));
	int n = find(headptr, 10);
	printf("查找10在第%d个节点\n", n);
	erase(&headptr, n);
	travel(headptr);
	n = find(headptr, 10);
	printf("查找10在第%d个节点\n", n);
	erase(&headptr, n);
	travel(headptr);
	setdata(headptr, 10, 100);
	setdata(headptr, 2, 99);
	travel(headptr);
	clear(&headptr);
	printf("剩余%d个数据\n", listsize(headptr));
	return 0;
}
