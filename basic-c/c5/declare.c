#include <stdio.h>

int get()//�ղ������ʾ��������
{
	return 10;
}
int func(void)//��ȷ��ʾ�������в���
{
	return 20;
}
int main()
{
	printf("%d\n",get());
	printf("%d\n",get(123,"good",45.6));//�Ϸ�
	printf("%d\n",func());
//	printf("%d\n",func(123,"good",45.6));�Ƿ�
	return 0;
}
