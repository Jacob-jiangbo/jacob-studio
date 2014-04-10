#include <stdio.h>
int main()
{
	int score;
	printf("请输入成绩:");
	scanf("%d", &score);
	if(score<0||score>100)//如果是无效成绩
	{
		printf("无效成绩\n");
		printf("成绩必须在0～100之间\n");
	}
	else if(score==100)
	{
		printf("A\n");
	}
	else if(score>=90)
	{
		printf("B\n");
	}
	else if(score>=80)
	{
		printf("C\n");
	}
	else if(score>=70)
	{
		printf("D\n");
	}
	else if(score>=60)
	{
		printf("E\n");
	}
	else
	{
		printf("F\n");
	}
	return 0;
}

