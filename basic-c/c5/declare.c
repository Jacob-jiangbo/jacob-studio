#include <stdio.h>

int get()//空参数表表示参数不限
{
	return 10;
}
int func(void)//明确表示不允许有参数
{
	return 20;
}
int main()
{
	printf("%d\n",get());
	printf("%d\n",get(123,"good",45.6));//合法
	printf("%d\n",func());
//	printf("%d\n",func(123,"good",45.6));非法
	return 0;
}
