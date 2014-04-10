#include <stdio.h>

int main()
{
	double score, sum=0.0;
	int i=0;
	printf("请输入10个同学的成绩:\n");
	while(i<10)
	{
		scanf("%lf", &score);
		sum += score;
		++i;
	}
	printf("总成绩%.1f, 平均%.2f\n", sum, sum/10);
	return 0;
}

