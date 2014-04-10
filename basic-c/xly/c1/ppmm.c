#include <stdio.h>

int main()
{
	int a = 10;
	++a;
	printf("a=%d\n", a);
	a++;
	printf("a=%d\n", a);
	a = 10;
	int b = ++a;
	printf("++a=%d, a=%d\n", b, a);
	a = 10;
	int c = a++;
	printf("a++=%d, a=%d\n", c, a);
	return 0;
}

