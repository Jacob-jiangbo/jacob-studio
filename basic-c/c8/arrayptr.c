#include <stdio.h>

typedef int A[5];//A作为int[5]类型的别名
int main()
{
	int a[5]={11,22,33,44,55};
	printf("a=%p, &a=%p\n", a, &a);
	printf("%d, %d\n", *a, a[0]);
	//a表示a[0]的地址，因为a[0]是int，所以a的类型是int*
	//&a表示整个数组a的地址，类型是A*
	int* p = a;
	A* q = &a;// *q <==> a
	printf("%d, %d\n", (*q)[1], a[1]);
	int(*b)[5] = &a;//b==&a, *b==a
	printf("%d, %d\n", (*b)[2], a[2]);
	return 0;
}
