#include <stdio.h>

int main()
{
	int x=100;
	double a[4];
	int y=200;
	printf("a=%p, &x=%p, &y=%p\n", a, &x, &y);
	int i;
	for(i=0; i<4; i++)
		printf("&a[%d]=%p\n", i, &a[i]) ;
	for(i=0; i<4; i++)
		printf("a+%d=%p\n", i, a+i) ;
	return 0;
}

