#include <stdio.h>

int main()
{
	int x=100;
	int a[4]={11,22,33,44};
	int y=200;
	int i;
	for(i=0; i<sizeof(a)/sizeof(*a); i++)
		printf("%d ", a[i]);
	printf("\n");
	for(i=-4; i<8; i++)//Խ��������ݣ��۲�100(x)��200(y)��λ��
		printf("%d ", a[i]);
	printf("\n");
	a[4] = 888;//�ƻ�x��ֵ
	a[5] = 999;//�ƻ�y��ֵ
	printf("x=%d, y=%d\n", x, y);
	for(i=0; i<100; i++)//����Խ����ܵ��³������
		a[i] = 0;
	printf("welcome to ...\n");
	return 0;
}
