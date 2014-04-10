#include <stdio.h>
#include <time.h>

void sort(int a[], int n);

void init(int a[], int n)
{
	int i;
	for(i=0; i<n; i++)
		a[i] = n-i;
}
void print(int a[], int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%d ", *a++);
	printf("\n");
}
int main()
{
	const int N=10240;
	int a[N];
	init(a, N);
	print(a, 10);
	clock_t t1 = clock();
	sort(a, N);
	clock_t t2 = clock();
	print(a, 10);
	printf("time:%g\n",(double)(t2-t1)/CLOCKS_PER_SEC);
	return 0;
}
