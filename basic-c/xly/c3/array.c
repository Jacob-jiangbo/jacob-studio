#include <stdio.h>
#include <string.h>
/*
数组定义：元素类型 数组名[元素个数];
元素个数需要是个非负整数常量（gcc编译器允许用变量，但C标准不允许）
未初始化的数组中每个元素都是垃圾数据
数组初始化（只能在数组定义的时候）：元素类型 数组名[元素个数]={初始值列表};
初始值数据个数如果比元素个数少，剩余的元素全部用数值零初始化
没有一次性访问整个数组的方法，只能一次访问一个元素，格式：数组名[下标]
下标从0开始，到元素个数-1为止，下标超出范围称为越界
每个数组元素都可以单独当成一个变量
*/
int main()
{
	int b[3]={10,20,30};
	int a[5];//a[0],a[1],a[2],a[3],a[4],注意：不会有a[5]!!
	int c[8]={40,50,60,70,80/*,0,0,0*/};
	//printf("%d,%d,%d,%d,%d\n", a[0],a[1],a[2],a[3],a[4]);
	int i;
	for(i=0; i<5; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	for(i=-5; i<10; i++)//下标越界可能访问到其它变量的数据甚至段错误
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	a[0] = 123;
	a[3] = 456;
	a[5] = 789;//越界，可能破坏别的变量的数据！！
	for(i=0; i<5; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	int t=b[1];
	b[1] = b[2];
	b[2] = t;
	for(i=0; i<3; i++)
	{
		printf("%d ", b[i]);
	}
	printf("\n");
	for(i=0; i<8; i++)
	{
		printf("%d ", c[i]);
	}
	printf("\n");
	printf("请输入5个整数:");
	for(i=0; i<5; i++)
		scanf("%d", &a[i]);
	for(i=0; i<5; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	int d[5]/*=a不可以这样初始化*/;
	//d = a;不可以这样赋值
	for(i=0; i<5; i++)
	{
		d[i] = a[i];
	}
	int e[5];
	memcpy(&e, &a, sizeof(a));
	for(i=0; i<5; i++)
	{
		int j;
		for(j=i+1; j<5; j++)
		{
			if(d[j]<d[i])
			{
				int t=d[j];
				d[j] = d[i];
				d[i] = t;
			}
		}
	}
	for(i=0; i<5; i++)
	{
		printf("%d ", d[i]);
	}
	printf("\n");
	for(i=0; i<5; i++)
	{
		printf("%d ", e[i]);
	}
	printf("\n");
	return 0;
}

