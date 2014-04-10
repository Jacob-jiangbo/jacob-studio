#include <stdio.h>
//输入用的格式占位符跟输出的一样
/*
%hd	short
%d	int
%ld	long
%f	float
%lf	double
%c	char
%s	字符串
*/
int main()
{
	int a, b;
	printf("请输入两个整数:");
	scanf("%d %d", &a, &b);//一定要&取地址！！！
	printf("%d\n", a+b);
	return 0;
}

