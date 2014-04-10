#include <stdio.h>

void decbit(int n)
{
	if(n>=10){
		decbit(n/10);
		printf(" ");
	}
	printf("%d", n%10);
}
int main()
{
	int n;
	printf("请输入一个整数:");
	scanf("%d", &n);
	decbit(n);
	printf("\n");
	return 0;
}
