#include <stdio.h>

int f(int n)
{
	if(n==0) return 8;//f(0) = 8
	return 2*f(n-1)+5;//f(n) = 2*f(n-1)+5
}
int main()
{
	printf("%d\n", f(3));
	return 0;
}
