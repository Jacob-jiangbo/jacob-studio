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
	printf("������һ������:");
	scanf("%d", &n);
	decbit(n);
	printf("\n");
	return 0;
}
