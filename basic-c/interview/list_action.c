#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node
{
    int data;
    struct node * next;
}node;


void createlist(node** pptr)
{
    *pptr = NULL;
}


int listsize(node * headptr)
{
    int index = 0;
    while(headptr != NULL)
    {
        headptr = headptr->next;
	index++;
    }	    
    return index;
}

node ** getptraddr(node** headpptr, int index)
{
    int len = listsize(*headpptr);
    if(index < 0 || index > len)
    {
        fprintf(stderr, "invalid pointer%d\n", index);
	index = len;
    }	    
    if(index == 0)
        return headpptr;
    node* p = * headpptr;
    int i;
    for(i=1; i<index; i++)
        p = p->next;            
    return &(p->next);
}

void insert(node** headpptr, int data, int index)
{
    node** ptraddr = getptraddr(headpptr, index);
    node *p = malloc(sizeof(node));
    if (p == NULL)
        return;
    p->data = data;
    p->next = * ptraddr;
    *ptraddr = p;
}

void revert(node** headpptr)
{
    printf("revert list\n");

    node * p2 = NULL;
    node * p1 = * headpptr;
    
    if ((*headpptr) == NULL)//null list
        return;

    node * p = (*headpptr)->next;
    while(p)
    {
        p2 = p->next;
	p->next = p1;
	p1 = p;
	p = p2;
    }	    

    (*headpptr)->next = NULL;
    * headpptr = p1;

    return;
}

void travel(node* headptr)
{
    int index = 1;	
    while(headptr != NULL)
    {
        printf("index %d is %d\n", index, headptr->data);
        headptr = headptr->next;	
	index ++;
    }	    
}


int main()
{
    node * headptr;
    createlist(&headptr);

    insert(&headptr, 10, 2);
    insert(&headptr, 20, 0);
    insert(&headptr, 30, 2);
    insert(&headptr, 40, 1);
    insert(&headptr, 50, 8); //20,40, 10, 30, 50,	    
    travel(headptr);

    revert(&headptr);
    travel(headptr);

    return 0;
}


