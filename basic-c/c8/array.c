#include <stdio.h>

//void print(int x[], int n)
void print(int* x, int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%d ", x[i]);//x[i]==>*(x+i)
	printf("\n");
	printf("sizeof x=%d\n", sizeof(x));
	x = &i;
}
int main()
{
	int a[5]={11,22,33,44,55};
	int* p = a;
	printf("a=%p, p=%p\n", a, p);
	p = a+3;
	*p = 888;
	print(a, 5); 
	p = a;
	int i;
	for(i=0; i<5; i++)
		printf("%d,%d,%d,%d ", *(a+i), *(p+i), a[i], p[i]);
	printf("\n");
	p = a+3;
	printf("%d, %d, %d\n", *(p-2), p[-2], p[-3]);
	printf("%d, %d\n", p[0], p[1]);
	printf("p=%p, a=%p, p-a=%d\n", p, a, p-a);
	p = a;
	for(i=0; i<5; i++)
		printf("%d ", *p++);
	printf("\n");
	for(i=0; i<5; i++)
		printf("%d ", *--p);
	printf("\n");
	return 0;
}
