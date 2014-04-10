#include <stdio.h>

double/*int是返回类型*/ power/*power是函数名*/(double x, int n/*x和n是形参变量*/)
/*(int x, int n)是参数表*/
{
	double r=1;
	int i;
	for(i=0; i<n; i++)	r *= x;
	return r;
}
//以上是power函数的定义
int/*int是返回类型*/ main/*main是函数名*/()/*()是参数表*/
/*下面一对大括号及其里面的内容是函数体*/
{
	int a=2, b=10;
	printf("hello, 函数!\n");
	printf("%f\n", power(5,3/*5和3是实参*/)/*调用power函数*/);
	printf("%f\n", power(a,b/*a和b是实参*/)/*调用power函数*/);
	printf("%f\n", power(b,a*4/*b和a*4是实参*/)/*调用power函数*/);
	return 0;
}

