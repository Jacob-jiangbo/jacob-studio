#include <stdio.h>

int main()
{
	int a[3][5];//3��int[5]:a[0],a[1],a[2]
	char we[4][20]={"������","������","������","������"};//4��char[20]
	int i;
	for(i=0; i<4; i++)
		printf("���%s!\n", we[i]);
	return 0;
}

