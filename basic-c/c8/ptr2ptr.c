#include <stdio.h>

void getmax(double* * m, double* x, double* y)
{
	//*m就是p
	if(*x>=*y)
		*m = x;
	else
		*m = y;
}
int main()
{
	double a, b;
	printf("input 2 float numbers:");
	scanf("%lf%lf", &a, &b);
	double* p;
	getmax(&p, &a, &b);
	printf("max:%f\n", *p);
	//printf("%p\n", &&a);不存在“地址的地址”
	printf("&a=%p, &b=%p\n", &a, &b);
	printf("p=%p, &p=%p\n", p, &p);
	double** q = &p;
	double*** r = &q;//*r==q, **r==*q==p, ***r==**q==*p==大者
	printf("%f\n", ***r);
	return 0;
}
