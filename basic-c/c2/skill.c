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

