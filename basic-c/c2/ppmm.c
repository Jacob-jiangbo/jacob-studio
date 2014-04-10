#include <stdio.h>
int main()
{
	int a, b, c, d;
	a = b = c = d = 10;
	printf("a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
	printf("%d\n", ++a);
	printf("%d\n", b++);
	printf("%d\n", --c);
	printf("%d\n", d--);
	printf("a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
	int x = 10;
	printf("%d, %d, %d\n", ++x, ++x, ++x);
	int y = 10;
	printf("%d, %d, %d\n", y++, y++, y++);
	return 0;
}

