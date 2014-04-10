#include <stdio.h>
#include "date.h"
#include "date.h"
extern double x;//外部变量声明，声明存在一个在其它地方定义的全局变量
int main()
{
	int y, m, d;//局部变量，未初始化时是垃圾数据
	int sum;
	printf("%f\n", x);
	x = 123.45;
	printf("%f\n", x);
	printf("请输入一个日期:");
	scanf("%d-%d-%d", &y, &m, &d);
	sum = alldays(y,m,d);
	printf("总共第%d天，星期%d\n", sum, sum%7);
	return 0;
}
//double x=666.6;//全局变量，默认初始化为数值0
//double x;//全局变量，默认初始化为数值0
