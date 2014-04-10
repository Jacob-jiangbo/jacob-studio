#include <stdio.h>

int main()
{
	double score;
	do{
		printf("考试……完毕请输入成绩:");
		scanf("%lf", &score);
	}while(score<60);
	printf("恭喜你过关了\n");
	return 0;
}

