#include <stdio.h>

void print(double x[], int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%g ", x[i]);
	printf("\n");
}
void zero(double x[], int n)
{
	int i;
	for(i=0; i<n; i++)
		x[i] = 0.0;
}
void input(double x[], int n)
{
	printf("请输入%d个小数:\n", n);
	int i;
	for(i=0; i<n; i++)
		scanf("%lf", &x[i]);
}
void reverse(double x[], int n);
/*void swap(double* d1, double* d2)
{
	double t=*d1;
	*d1 = *d2;
	*d2 = t;
}
#define SWAP(x,y) swap(&x,&y);*/
#define SWAP(x,y) {double t=x;x=y;y=t;}
void sort(double a[], int n)
{
	int i, j;
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(a[j]<a[i]){
				//swap(&a[j], &a[i]);
				SWAP(a[j], a[i])
//				double t=a[i];
	//			a[i] = a[j];
		//		a[j] = t;
			}
		}
	}
}
int main()
{
	double a[5]={1.1,2.2,3.3,4.4,5.5};
	print(a,5);
	zero(a,5);
	print(a,5);
	input(a,5);
	print(a,5);
	reverse(a,5);
	print(a,5);
	sort(a, 5);
	print(a,5);
	return 0;
}
void reverse(double x[], int n)
{
	int i;
	for(i=0; i<n/2; i++)
	{
		double t=x[i];
		x[i] = x[n-1-i];
		x[n-1-i] = t;
	}
}
