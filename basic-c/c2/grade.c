#include <stdio.h>
int main()
{
	int score;
	printf("������ɼ�:");
	scanf("%d", &score);
	if(score<0||score>100)//�������Ч�ɼ�
	{
		printf("��Ч�ɼ�\n");
		printf("�ɼ�������0��100֮��\n");
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

