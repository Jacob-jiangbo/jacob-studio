#include <stdio.h>

int main()
{
	int a, b;
	printf("请输入两个整数:");
	scanf("%d %d", &a, &b);
	printf("请听题:它们的和是多少?");
	int sum;
	scanf("%d", &sum);
	if(sum==a+b)
	{
		printf("恭喜你答对了!\n");
	}
	else
	{
		printf("很遗憾，和为%d\n", a+b);
	}
	return 0;
}

