#include <stdio.h>

typedef int A[5];//A��Ϊint[5]���͵ı���
int main()
{
	int a[5]={11,22,33,44,55};
	printf("a=%p, &a=%p\n", a, &a);
	printf("%d, %d\n", *a, a[0]);
	//a��ʾa[0]�ĵ�ַ����Ϊa[0]��int������a��������int*
	//&a��ʾ��������a�ĵ�ַ��������A*
	int* p = a;
	A* q = &a;// *q <==> a
	printf("%d, %d\n", (*q)[1], a[1]);
	int(*b)[5] = &a;//b==&a, *b==a
	printf("%d, %d\n", (*b)[2], a[2]);
	return 0;
}
