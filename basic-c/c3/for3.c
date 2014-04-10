#include <stdio.h>
int main()
{
	for(;;)
	{
		int y;
		printf("请输入年份:");
		if(scanf("%d",&y)!=1) return 0;
		if(y==0) break;
		if(y<0) continue;
		if(y%4==0&&y%100!=0 || y%400==0)
			printf("%d是闰年\n", y);
		else
			printf("%d不是闰年\n", y);
	}
	printf("再见\n");
	return 0;
}

