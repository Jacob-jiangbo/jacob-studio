#include <stdio.h>
//�β��е�������ʵ����������Ƥ��ָ��
//void func(double a[], int n)
void func(double* a, int n)
{
	//a = NULL;���벻�ᱨ����ָ�븳ֵ�ǺϷ���
	printf("size of a: %d\n", sizeof(a));//ָ�룬4�ֽ�
	int i;
	for(i=0; i<n; i++)
		printf("%g ", a[i]);
	printf("\n");
}
int main()
{
	double d[10]={1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10};
	//d = NULL;������󣺲�������������ٸ�ֵ
	printf("size of d: %d\n", sizeof(d));//���飬80�ֽ�
	func(d, 10);
	return 0;
}

