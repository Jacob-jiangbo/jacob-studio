#include <stdio.h>

int main()
{
	double score;
	do{
		printf("���ԡ������������ɼ�:");
		scanf("%lf", &score);
	}while(score<60);
	printf("��ϲ�������\n");
	return 0;
}

