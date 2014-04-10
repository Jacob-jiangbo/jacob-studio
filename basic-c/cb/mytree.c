#include <stdio.h>
#include <stdlib.h>
#define less(a,b) (a)<(b)
typedef int T;
typedef struct node{
	T data;
	struct node* R;
	struct node* L;
}node;

void create(node** rootptraddr)
{
	*rootptraddr = NULL;
}

void inserttree(node** rootptraddr, node* p)
{	if(*rootptraddr == NULL)
		*rootptraddr = p;
	else if(less(p->data, (*rootptraddr)->data))
		inserttree(&(*rootptraddr)->L, p);
	else	inserttree(&(*rootptraddr)->R, p);
}

void insert(node** rootptraddr, T data)
{	node* p = malloc(sizeof(node));
	p->data = data;
	p->R = p->L = NULL;
	inserttree(rootptraddr, p);
}

void travel(node* rootptr)
{	if(NULL == rootptr)	return;
	travel(rootptr->L);
	printf("%d  ", rootptr->data);
	travel(rootptr->R);
}
node** find(node** rootptraddr, T data)
{	if(NULL == *rootptraddr) return NULL;
	else if((*rootptraddr)->data == data) return rootptraddr;
	else if(less(data, (*rootptraddr)->data))
			return find(&(*rootptraddr)->L, data);
	return find(&(*rootptraddr)->R, data);
}

int erase(node** rootptraddr, T data)
{	node** pp = find(rootptraddr, data);
	if(NULL == 	pp) return 0;
	if((*pp)->L) 
		inserttree(&(*pp)->R, (*pp)->L);
	node* t = (*pp)->R;
	free(*pp);
	*pp = t;
	return 1;
}
void updata(node** rootptraddr, T olddata, T newdata)
{	if(!erase(rootptraddr, olddata))
		return;
	insert(rootptraddr, newdata);
}

void clear(node** rootptraddr)
{	if(NULL == *rootptraddr)
		return;
	clear(&((*rootptraddr)->L));
	clear(&((*rootptraddr)->R));
	free(*rootptraddr);
	*rootptraddr = NULL;
}	

int treehigh(node* rootptr)
{	if(NULL == rootptr) return 0;
	int i = 1+ ((treehigh(rootptr->L)<treehigh(rootptr->R))?treehigh(rootptr->R):treehigh(rootptr->L));
	return i;	
}
/*
void print(node** rootptraddr)
{	if(NULL == *rootptraddr) printf("\n");
	printf("  %d\n", (*(find(rootptraddr, ((*rootptraddr)->R)->data)))->data);
	printf("%d\n", (*rootptraddr)->data);
	printf("  %d\n", (*(find(rootptraddr, ((*rootptraddr)->L)->data)))->data);
}
*/
void print(node* rootptr)
{	if(NULL == rootptr) return;
	printf("  "); print(rootptr->R); printf("\n");
	printf("%d\n", rootptr->data);
	printf("  "); print(rootptr->L); printf("\n");
}

int main()
{	node* rootptr;
	create(&rootptr);
	insert(&rootptr, 60);
	insert(&rootptr, 50);
	insert(&rootptr, 70);
	insert(&rootptr, 40);
	insert(&rootptr, 30);
//	insert(&rootptr, 60);
	travel(rootptr);
//	node** p = find(&rootptr, 20);
//	printf("%p\n" ,p);
//	erase(&rootptr, 30);
//	travel(rootptr);
//	printf("\n");
//	updata(&rootptr, 10, 90);
//	travel(rootptr);
//	printf("\n");
	int high = treehigh(rootptr);
	printf("high: %d\n", high);
	print(rootptr);
//	clear(&rootptr);
	return 0;
}

