#include <stdio.h>

void f1(){printf("我是可爱的f1\n");}
void f2(){printf("我是潇洒的f2\n");}
void func(void(*f)())
{
	printf("传递过来的函数地址是%p\n", f);
	(*f)();
	printf("bye\n");
}
int main()
{
	printf("&main=%p, &f1=%p, &f2=%p\n", &main, &f1, &f2);
	char c;
	printf("1--f1, 2--f2:");
	scanf(" %c", &c);
	func(c=='1'?&f1:&f2);
	return 0;
}
