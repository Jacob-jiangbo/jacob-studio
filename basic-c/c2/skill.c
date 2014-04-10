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
	else if(score>=60)
	{
		printf("%c\n", 'F'-(score/10-5));
	}
	else
	{
		printf("F\n");
	}
	return 0;
}

