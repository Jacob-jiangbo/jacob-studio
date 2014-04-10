int maxcd(int a, int b)
{
	int big = a>b?a:b;
	int small = a>b?b:a;
	if(small==0) return big;
	return maxcd(small, big%small);
	if(a==0||b==0)//如果有一方为0
		return a+b;//最大公约数就是非0的那一个
	return a<b?maxcd(a,b%a):maxcd(b, a%b);
}
//int maxcd(int a, int b){return b==0?a:maxcd(b,a%b);}
#include <stdio.h>
int main()
{
	int a, b;
	printf("请输入两个非负整数:");
	scanf("%d%d", &a, &b);
	printf("%d\n", maxcd(a,b));
	return 0;
}
