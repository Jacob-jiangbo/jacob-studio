#include <stdio.h>
int main()
{
	int data;//用来保存每个输入的数据
	int sum=0;//用来保存总和
	int n=0;//用来保存数据的个数
	printf("请输入一系列整数，用非数字字符结束:\n");
	while(scanf("%d",&data)==1)
	{
		sum = sum + data;//sum += data;
		++n;//n++;
	}
	printf("%d个整数，总和%d\n", n, sum);
	return 0;
}

