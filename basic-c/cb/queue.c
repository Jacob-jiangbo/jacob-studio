/*
队列queue是一种受限线性表，插入和删除必须在不同端。
基本操作：
v创建create，建一个空队列，有效元素个数为0；
v清空clear，把队列变成空队列，废弃所有有效元素；
v队首front，取得最先入队的那个元素；
v队尾back，取得最后入队的那个元素；
v入队push，把一个元素加入到队列中成为新的队尾；
v出队pop，把队首元素从队列中删除（废弃掉）；
v有效元素个数size，取得队列中有效元素个数；
v是否为空empty，判断队列是否是空，一般在出队和取首尾之前判断
是否满full，判断队列是否已满，一般在入队前判断
*/
#define T int
typedef struct node{//节点结构
	T data;
	struct node* next;
}node;
typedef struct queue{//队列结构
	node* headptr;//指向第一个节点
	node* tailptr;//指向最后一个节点
	int len;
}queue;

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//创建一个空队列
void create(queue* p)
{
	//memset(p, 0, sizeof(queue));可以用这个代替下面三句
	p->headptr = NULL;
	p->tailptr = NULL;
	p->len = 0;
}
//入队
void push(queue* p, T data)
{
	//准备节点
	node* t = (node*)malloc(sizeof(node));
	//if(t==NULL) {...}
	t->data = data;
	t->next = NULL;
	//把新节点挂接在原来的尾节点之后
	if(p->tailptr)
		p->tailptr->next = t;
	//让尾指针指向新的尾节点
	p->tailptr = t;
	//如果队列原来为空，新节点也是第一个节点
	if(p->headptr==NULL)
		p->headptr = p->tailptr;
	//节点个数增加
	p->len++;
}
//取得元素个数
int size(const queue* p)
{
	return p->len;
}
//判断是否为空
int empty(const queue* p)
{
	return p->headptr==NULL;
}
//出队，删除队首元素
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
//队首
T front(const queue* p)
{
	assert(!empty(p));
	return p->headptr->data;
}
//队尾
T back(const queue* p)
{
	assert(!empty(p));
	return p->tailptr->data;
}
//清空队列
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
