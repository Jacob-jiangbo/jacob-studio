#include <stdio.h>

#define N 10
int main()
{
	int a[N] = {0};//��������
	printf("size:%d\n", sizeof(a));
//	int x = 100;
//	printf("%d\n", sizeof(++x));
//	printf("%d\n", sizeof(++x));
//	
//	printf("%d\n", sizeof(x=123));
//	printf("%d\n", x);//100*/
	printf("%d,  %d,  %d,  %d\n",a[0],a[1],a[2],a[N-1]);/*,a[N]Խ��*/
	double d[N-3]={1.1,2.2,3.3};//�����ʼֵ��������������ֵ0���
	int i;
	for(i=0; i<N-3; i++)
		printf("%f ", d[i]);
	printf("\n");
	printf("������%d������:\n", N);
//	for(i=0; i<N; i++)
//		scanf("%d", &a[i]);
//	for(i=N-1; i>=0; i--)
//		printf("%d ", a[i]);
//	printf("\n");
	*d += 8.0;
	printf("*d=%f\n", *d);
	printf("d[0]=%f\n", d[0]);
	return 0;
}