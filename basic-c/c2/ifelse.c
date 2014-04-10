#include <stdio.h>
int main()
{
	int score;
	printf("请输入成绩:");
	scanf("%d", &score);
	printf("您输入的是%d\n", score);
	if(score<0||score>100)//如果是无效成绩
	{
		printf("无效成绩\n");
		printf("成绩必须在0～100之间\n");
	}
	else if(score==100)
	{
		printf("恭喜你得了满分!\n");
	}
	else if(score>=85)
	{
		printf("你的成绩优秀!\n");
	}
	else if(score>=70)
	{
		printf("你取得了良好的成绩!\n");
	}
	else if(score>=60)
	{
		printf("你顺利通过了考试!\n");
	}
	else
	{
		printf("请到办公室交补考费5元.\n");
	}
	return 0;
}

