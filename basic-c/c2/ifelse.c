#include <stdio.h>
int main()
{
	int score;
	printf("������ɼ�:");
	scanf("%d", &score);
	printf("���������%d\n", score);
	if(score<0||score>100)//�������Ч�ɼ�
	{
		printf("��Ч�ɼ�\n");
		printf("�ɼ�������0��100֮��\n");
	}
	else if(score==100)
	{
		printf("��ϲ���������!\n");
	}
	else if(score>=85)
	{
		printf("��ĳɼ�����!\n");
	}
	else if(score>=70)
	{
		printf("��ȡ�������õĳɼ�!\n");
	}
	else if(score>=60)
	{
		printf("��˳��ͨ���˿���!\n");
	}
	else
	{
		printf("�뵽�칫�ҽ�������5Ԫ.\n");
	}
	return 0;
}

