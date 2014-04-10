#include <stdio.h>

int main()
{	int i, j;
	int age[5][9]={
		{1,2,3,3},
		{23,23,23,},
		{23,23,23,},
		{234,524,45},
		{32,56,23,46,23}
	};
	for(i=0;i<5;i++)
	{	for(j=0;j<9;j++)
		{	printf("%d  ",age[i][j]);

		}
		printf("\n");
	}
//	printf()

	return 0;
}

