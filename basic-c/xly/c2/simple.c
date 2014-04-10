#include <stdio.h>

int last(void)//函数定义
{
	printf("欢迎使用自定义函数last!\n");
	return 0;
}
double func();//函数声明
int isleap(int year)
{
	if(year%4==0&&year%100!=0||year%400==0) return 1;
	else return 0;
}
int days(int year/*形参1*/, int month/*形参2*/)//参数表
{
	if(month==4||month==6||month==9||month==11)
		return 30;
	else if(month==2)
		return isleap(year)+28;
	else
		return 31;
}
void print_diamond(int n)
{
	int i, j;
	int b, e;
        for(i=1; i<2*n; i++)
        {
                //计算本行的星号位置
                b = (i<=n?(n-i+1):(i-n+1));
                e = 2*n - b;
                //反复2n－1次，每次打印一列
                for(j=1; j<2*n; j++)
                {
                        //如果是星号位置就打星号，
                        //if(j==b||j==e) printf("*");//打印空心菱形
                        if(j>=b&&j<=e) printf("*");//打印实心菱形
                        //否则就打空格
                        else printf(" ");
                }
                //打印换行符
                printf("\n");
        }
	//return;可有可无，但return后不允许带数据，因为返回类型是void
}
int main()
{
	func();//函数调用
	printf("欢迎使用main函数!\n");//函数调用
	printf("%g\n", func());//函数调用
	last();//函数调用
	printf("%d\n", isleap(2010));
	printf("%d\n", isleap(2008));
	printf("%d\n", days(2010,7));//调用函数，传递的数据叫实参
	print_diamond(5);
	print_diamond(4);
	//func(3,5,7,"hello",123.456);参数表为空，能通过编译
	//last(3);参数表是void，不能通过编译
	//printf("%d", print_diamond(3));返回类型是void，不带回结果
	return 0;
}
double func()//函数定义
{
	printf("欢迎使用自定义函数func!\n");
	return 1230.5;
}
/*
函数的形参以及函数里面的其它变量，都是每次调用的时候新分配内存空间，到从这个函数返回时这个空间才收回。如果这个函数再次被调用，会再分配一份新的内存空间，不影响旧的那一份
*/
