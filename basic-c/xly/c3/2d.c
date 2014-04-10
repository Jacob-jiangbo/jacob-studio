#include <stdio.h>

int main()
{
	int a[3][5];//3个int[5]:a[0],a[1],a[2]
	char we[4][20]={"王红涛","吴增峰","王江波","冯晓亮"};//4个char[20]
	int i;
	for(i=0; i<4; i++)
		printf("你好%s!\n", we[i]);
	return 0;
}

