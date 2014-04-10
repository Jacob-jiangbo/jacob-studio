#include <stdio.h>

int main()
{
	double d=123.45;
	double* p = &d;
	printf("p=%p\n", p);
	printf("&d=%p\n", &d);
	printf("%g\n", *p);
	*p = 678.9;
	printf("d=%g\n", d);
	double a[5]={1.1,2.2,3.3,4.4,5.5};
	p = a;
	printf("%g\n", *p);
	int i;
	for(i=0; i<5; i++)
		printf("%g ", p[i]);
	printf("\n");
	for(i=0; i<5; i++)
		printf("%g ", *p++);
	printf("\n");
	printf("%g\n", *p);
	return 0;
}

