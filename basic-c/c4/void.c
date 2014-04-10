#include <stdio.h>
#include <time.h>

void printrect(int row, int col)
{
	int i, j;
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			printf(" *"); 
		}
		printf("\n");
	}
//	return;
}
int gettime()
{
	unsigned t = time(NULL)+8*3600/*时区调整*/;
	unsigned s = t%(24*3600);
	unsigned m = s/60;
	unsigned h = m/60;
	return 10000*h + 100*(m%60) + s%60;
}
int main()
{
	printrect(3,5);
	printf("==================================\n");
	printrect(6,6);
	printf("现在时间:%06d\n", gettime());
	return 0;
}
