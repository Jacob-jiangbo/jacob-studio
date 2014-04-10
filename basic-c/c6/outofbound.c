#include <stdio.h>

int main()
{
	int x=100;
	int a[4]={11,22,33,44};
	int y=200;
	int i;
	for(i=0; i<sizeof(a)/sizeof(*a); i++)
		printf("%d ", a[i]);
	printf("\n");
	for(i=-4; i<8; i++)//越界访问数据，观察100(x)和200(y)的位置
		printf("%d ", a[i]);
	printf("\n");
	a[4] = 888;//破坏x的值
	a[5] = 999;//破坏y的值
	printf("x=%d, y=%d\n", x, y);
	for(i=0; i<100; i++)//过分越界可能导致程序崩溃
		a[i] = 0;
	printf("welcome to ...\n");
	return 0;
}
