#include <stdio.h>

double/*int�Ƿ�������*/ power/*power�Ǻ�����*/(double x, int n/*x��n���βα���*/)
/*(int x, int n)�ǲ�����*/
{
	double r=1;
	int i;
	for(i=0; i<n; i++)	r *= x;
	return r;
}
//������power�����Ķ���
int/*int�Ƿ�������*/ main/*main�Ǻ�����*/()/*()�ǲ�����*/
/*����һ�Դ����ż�������������Ǻ�����*/
{
	int a=2, b=10;
	printf("hello, ����!\n");
	printf("%f\n", power(5,3/*5��3��ʵ��*/)/*����power����*/);
	printf("%f\n", power(a,b/*a��b��ʵ��*/)/*����power����*/);
	printf("%f\n", power(b,a*4/*b��a*4��ʵ��*/)/*����power����*/);
	return 0;
}

