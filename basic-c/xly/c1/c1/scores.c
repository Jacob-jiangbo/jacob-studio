#include <stdio.h>

int main()
{
	double score, sum=0.0;
	int i=0;
	printf("������10��ͬѧ�ĳɼ�:\n");
	while(i<10)
	{
		scanf("%lf", &score);
		sum += score;
		++i;
	}
	printf("�ܳɼ�%.1f, ƽ��%.2f\n", sum, sum/10);
	return 0;
}

