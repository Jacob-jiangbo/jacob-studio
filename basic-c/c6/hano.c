#include <stdio.h>

//��n�����Ӵ�fromλ���ƶ���toλ�ã����Խ���spareλ��
void move(int n, char from, char to, char spare)
{
	//���û�����ӣ�ֱ�����
	if(n==0) return;
	//������n-1�����Ӵ�fromλ����ʱ�ƶ���spareλ�ã����Խ���toλ��
	move(n-1, from, spare, to);
	//�ѵ�n������ֱ�Ӵ�fromλ���ƶ���toλ��
	printf("%d�����Ӵ�%cλ�õ�%cλ��\n", n, from, to);
	//��spareλ���ϵ�n-1�������ƶ���toλ�ã����Խ���fromλ��
	move(n-1, spare, to, from);
}

int main()
{
	move(10, 'A', 'B', 'C');
	return 0;
}
