#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int A[10];
/*A*/void func(A a)//�������Ͳ�����������
{
	int i;
	//α�����
	srand(time(NULL));//������������ӣ�ֻ��Ҫ����һ��
	for(i=0; i<100; i++){
		int m = rand()%10;//ȡ��һ������������Է�������
		int n = rand()%10;
		int t=a[m];a[m]=a[n];a[n]=t;
	}
//	return a;
}
char* test(int n)
{
	/*static*/ char x[10]="hello";
	int i=0;
	while(x[i]) x[i++] += n;
	printf("%s\n", x);
	return x;
}
int main()
{
	A y={1,2,3,4,5,6,7,8,9,10};
	int i;
	func(y);
	for(i=0; i<10; i++) printf("%d ",y[i]); printf("\n");
	char* p = test(3);
	printf("***%s\n", p);
	func(y);
	printf("###%s\n", p);
//	int a, b;
//	if(a>b) int t=a;a=b;b=t;
	return 0;
}
