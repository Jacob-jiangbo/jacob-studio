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
v是否满full，判断队列是否已满，一般在入队前判断
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
//创建指定容量的空队列，返回成功与否
int create(queue* p, int capacity)
{
	p->a = calloc(capacity, sizeof(T));
	if(p->a==NULL) 
		return 0;
	p->capacity = capacity;
	p->len = 0;
	p->head = 0;
}
//入队
void push(queue* p, T data)
{
	assert(!full(p));
	p->a[(p->head+p->len++)%p->capacity] = data;
}
//取得元素个数
int size(const queue* p)
{
	return p->len;
}
//是否满
int full(const queue* p)
{
	return p->len==p->capacity;
}
//是否空
int empty(const queue* p)
{
	return p->len==0;
}
//队首
T front(const queue* p)
{
	assert(!empty(p));
	return p->a[p->head];
}
//出队
void pop(queue* p)
{
	assert(!empty(p));
	p->head = (p->head+1)%p->capacity;
	p->len--;
}
//队尾
T back(const queue* p)
{
	return p->a[(p->head+p->len-1)%p->capacity];
}
//清空
void clear(queue* p)
{
	p->len = 0;
}
//释放
void release(queue* p)
{
	free(p->a);
	p->a = NULL;
	p->head = 0;
	p->len = 0;
	p->capacity = 0;
}
//队列数据展示
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
