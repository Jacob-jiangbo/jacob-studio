#include <stdio.h>

int main()
{
	int a, b;
	printf("��������������:");
	scanf("%d %d", &a, &b);
	printf("������:���ǵĺ��Ƕ���?");
	int sum;
	scanf("%d", &sum);
	if(sum==a+b)
	{
		printf("��ϲ������!\n");
	}
	else
	{
		printf("���ź�����Ϊ%d\n", a+b);
	}
	return 0;
}

