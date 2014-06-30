#include <stdio.h>

typedef struct base
{
    //(void)*func(void);    <------ Wrong
    //void *func(void);     <------ Wrong
    void (*func)(void);
}base;

void act1(void)
{
    printf("I am act1!\n");
}

void act2(void)
{
    printf("I am act2!\n");
}

//void init_base(base* act, void *func(void)) <-- Right
void init_base(base* act, void (*func)(void))
{
    act->func = func;    
}

int main()
{
    base list[3] = {0};
    init_base(&list[0], act1);
    init_base(&list[1], act2);

    list[0].func();
    list[1].func();

    return 0;
}

