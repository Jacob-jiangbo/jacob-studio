#include <stdio.h>

void swap(int* x, int* y)
{
	int t=*x;*x=*y;*y=t;
}
int asc(int x, int y)//��С�������
{
	if(y<x) return 1;
	else return 0;
}
int dsc(int x, int y)//�Ӵ�С����
{
	if(x<y) return 1;
	else return 0;
}
void sort(int a[], int n, int(*f)(int,int))
{
	int i, j;
	for(i=0; i<n; i++)
		for(j=i+1; j<n; j++)
			if((*f)(a[i],a[j]))//�����Ҫ�����ͷ�����
				swap(a+i,a+j);
} 
int last(int x, int y)//��λ��С�������
{
	if(y%10<x%10) return 1;
	else return 0;
}
int main()
{
	int a[10]={31,92,26,63,45,18,59,104,87,70};
	int i;
	sort(a,10,&asc);
	for(i=0; i<10; i++)printf("%d ",a[i]);printf("\n");
	sort(a,10,&dsc);
	for(i=0; i<10; i++)printf("%d ",a[i]);printf("\n");
	sort(a,10,&last);
	for(i=0; i<10; i++)printf("%d ",a[i]);printf("\n");
	return 0;
}
