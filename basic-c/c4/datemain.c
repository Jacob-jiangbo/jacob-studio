#include <stdio.h>
#include "date.h"
#include "date.h"
extern double x;//�ⲿ������������������һ���������ط������ȫ�ֱ���
int main()
{
	int y, m, d;//�ֲ�������δ��ʼ��ʱ����������
	int sum;
	printf("%f\n", x);
	x = 123.45;
	printf("%f\n", x);
	printf("������һ������:");
	scanf("%d-%d-%d", &y, &m, &d);
	sum = alldays(y,m,d);
	printf("�ܹ���%d�죬����%d\n", sum, sum%7);
	return 0;
}
//double x=666.6;//ȫ�ֱ�����Ĭ�ϳ�ʼ��Ϊ��ֵ0
//double x;//ȫ�ֱ�����Ĭ�ϳ�ʼ��Ϊ��ֵ0
