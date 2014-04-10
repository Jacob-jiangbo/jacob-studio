#include <stdio.h>
//形参中的数组其实是披着数组皮的指针
//void func(double a[], int n)
void func(double* a, int n)
{
	//a = NULL;编译不会报错，给指针赋值是合法的
	printf("size of a: %d\n", sizeof(a));//指针，4字节
	int i;
	for(i=0; i<n; i++)
		printf("%g ", a[i]);
	printf("\n");
}
int main()
{
	double d[10]={1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10};
	//d = NULL;编译错误：不允许给数组名再赋值
	printf("size of d: %d\n", sizeof(d));//数组，80字节
	func(d, 10);
	return 0;
}

