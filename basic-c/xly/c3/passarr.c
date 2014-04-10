#include <stdio.h>

void print(int x[], int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%d ", x[i]);
	printf("\n");
}
void add(int x[], int n)
{
	int i;
	for(i=0; i<n; i++)
		x[i]++;
}
int main()
{
	int a[5]={1,2,3,4,5};
	int b[6]={11,22,33,44,55,66};
	add(b, 6);
	print(a, 5);
	print(b, 6);
	return 0;
}

