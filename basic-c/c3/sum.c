#include <stdio.h>
int main()
{
	int data;//��������ÿ�����������
	int sum=0;//���������ܺ�
	int n=0;//�����������ݵĸ���
	printf("������һϵ���������÷������ַ�����:\n");
	while(scanf("%d",&data)==1)
	{
		sum = sum + data;//sum += data;
		++n;//n++;
	}
	printf("%d���������ܺ�%d\n", n, sum);
	return 0;
}

