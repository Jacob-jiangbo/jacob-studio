#include <stdio.h>
//�����õĸ�ʽռλ���������һ��
/*
%hd	short
%d	int
%ld	long
%f	float
%lf	double
%c	char
%s	�ַ���
*/
int main()
{
	int a, b;
	printf("��������������:");
	scanf("%d %d", &a, &b);//һ��Ҫ&ȡ��ַ������
	printf("%d\n", a+b);
	return 0;
}

