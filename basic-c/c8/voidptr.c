#include <stdio.h>
//this func 考察的知识点
//void*p 在函数形参中可以接受任何类型的指针类型
void show(void* p,int bytes)//这样的p可以接受任何类型的函数
{
	unsigned char* q = (unsigned char*)p;
	int i;
	for(i=0; i<bytes; i++)	printf("%x ", q[i]);//*q++);
	printf("\n");
}
int main()
{
	char c='a';//0x61
	short s=0x1234;
	int n=0x56789abc;
	float f=4.0;
	double d=4.8;
	show(&c, sizeof(c));
	show(&s, sizeof(s));
	show(&n, sizeof(n));
	show(&f, sizeof(f));
	show(&d, sizeof(d));
	return 0;
}
