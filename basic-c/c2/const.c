#include <stdio.h>
//#define PI "3.14"//3.14159
const double PI=3.1416;

int main()
{
	double d1, d2;
	int r=5;
	d1 = 2*PI*r;
	d2 = PI*r*r;
	printf("�ܳ�%f�����%f\n", d1, d2);
//	PI = 3.141593;�еı�����������
	printf("%f\n", PI);
	d1 = 3.0;
	return 0;
}

