#include <stdio.h>
int main()
{
	printf("%d\n", 20/8);//OK
	printf("%f\n", 20/8);//?
	printf("%d\n", 20/8.0);//?
	printf("%f\n", 20/8.0);//OK
	printf("%f\n", 1234567890);//2.500001
	int a=20, b=8;
	printf("%f\n", 0.0);
	printf("%f\n", (double)a/b);
	printf("%f\n", 1.0*a/b);//2.5
	printf("%f\n", a/b*1.0);//2.0
	return 0;
}

