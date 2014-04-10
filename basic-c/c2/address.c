#include <stdio.h>

int main()
{
	double d=1.23;
	char c;
	int n=0;
	short s;
	printf("%p\n", &d);
	printf("%p\n", &c);
	printf("%p\n", &n);
	printf("%p\n", &s);
	printf("%f\n", *&d);
	*&n = 4567;
	printf("%d\n", n);
	return 0;
}

