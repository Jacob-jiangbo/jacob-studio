#include <stdio.h>
#include <time.h>

//bubble
/*
void sort(int a[], int n)
{
	register int swap;
	register int i;
	do{
		--n;
		swap = 0;
		for(i=0; i<n; i++){
			if(a[i+1]<a[i]){
				int t=a[i+1];
				a[i+1]=a[i];
				a[i] = t;
				++swap;
			}
		}
	}while(swap>0);
}
*/


//反复N-1次（让i从0到<N-1）
//把最小的未序数据跟第一个未序数据交换（成为已序数据）
//	未序数据下标从i到N-1
void sort(int* a, int n)
{
	int i, j, min;
	for(i=0; i<n-1; i++){
		min = i;
		for(j=i+1; j<n; j++){
			if(a[j]<a[min]){
				min = j;
			}
		}
		int t=a[min];
		a[min]=a[i];
		a[i] = t;
	}
}



void init(int a[], int n)
{
	int i;
	for(i=0; i<n; i++)
		a[i] = n-i;
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

