#include <stdio.h>

void clearinput();//函数的显式声明，必须跟定义一致
int inputin(int a, int b);//尽管这个函数可以用潜规则隐式声明，但最好还是显式声明
int inputin(int, int);//在函数声明中，形参的名字可以不写，但还是建议写上
int weekday(int year, int month, int day);
int main()
{
	int n;
	n = inputin(1,10);
	printf("n=%d\n", n);
	n = inputin(6,3);
	printf("n=%d\n", n);
	return 0;
}
void func()
{
	printf("一个孤立的函数\n");
}
int inputin(int a, int b)//让用户输入a到b之间（含）的一个整数并返回这个整数
{
	int data;
	printf("输入一个%d～%d的整数:",a,b);
	while(scanf("%d", &data)!=1||(data-a)*(data-b)>0)
	{
		clearinput();//潜规则：假设clearinput函数的返回类型为int
		printf("输入无效，请重新输入!\n");
	}
	return data;
}
//函数定义，清除输入缓冲区中的字符序列
void clearinput()
{
	char c;
	do{
		scanf("%c", &c);
	}while(c!='\n');
}
