#include <stdio.h>

void clearinput();//��������ʽ���������������һ��
int inputin(int a, int b);//�����������������Ǳ������ʽ����������û�����ʽ����
int inputin(int, int);//�ں��������У��βε����ֿ��Բ�д�������ǽ���д��
int weekday(int year, int month, int day);
int main()
{
	int n;
	n = inputin(1,10);
	printf("n=%d\n", n);
	n = inputin(6,3);
	printf("n=%d\n", n);
	return 0;
}
void func()
{
	printf("һ�������ĺ���\n");
}
int inputin(int a, int b)//���û�����a��b֮�䣨������һ�������������������
{
	int data;
	printf("����һ��%d��%d������:",a,b);
	while(scanf("%d", &data)!=1||(data-a)*(data-b)>0)
	{
		clearinput();//Ǳ���򣺼���clearinput�����ķ�������Ϊint
		printf("������Ч������������!\n");
	}
	return data;
}
//�������壬������뻺�����е��ַ�����
void clearinput()
{
	char c;
	do{
		scanf("%c", &c);
	}while(c!='\n');
}
