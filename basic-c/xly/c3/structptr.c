#include <stdio.h>

typedef struct Course{
	char name[50];
	int days;
} CS;
void print(const CS* p)//const表示通过这个地址对变量进行只读操作
{
	printf("%s:%d\n", (*p).name, (*p).days);
	printf("%s:%d\n", p->name, p->days);
	//p->days++;编译错误：对承诺只读的数据试图进行修改
}
int main()
{
	CS c={"C语言基础",6};
	print(&c);
	print(&c);
	return 0;
}

