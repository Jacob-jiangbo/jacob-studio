#include <stdio.h>
#include "my.h"
//extern int y;��Ϊy��b.c�ж����static����������ļ�ʹ��
void sfunc();
int main()
{
	printf("x=%d\n", x);
//	printf("y=%d\n", y);
	func();
	//sfunc();��Ϊsfunc��b.c�ж����static�ģ���������ļ�ʹ��
	return 0;
}
