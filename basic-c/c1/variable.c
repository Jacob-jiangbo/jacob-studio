#include <stdio.h>
int main()
{
	int a = 123456;//���岢��ʼ��
	int b;//���嵫û�г�ʼ������ʾһ���޷�Ԥ֪�����ݣ��������ݣ�
	printf("%d,%d\n",a,b);
	b = 789;
	a = 88888;
	printf("%d,%d\n",a,b);
	double salary = 2999.99;//2999.99F��ʾfloat���ͣ���ȷ�ȵ�
	printf("����%f\n", salary);
	char gender='M'/*'F'*/;//male,female
	printf("%c,%d\n",gender,gender);
	return 0;
}

