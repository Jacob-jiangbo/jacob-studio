#include <stdio.h>
typedef struct date{
	int y;
	int m;
	int d;
}date;
int main()
{
	int a=0x78654321;
	int* pi = &a;//��ȷָ��a
	date* pdate;//Ұָ�룬û׼��ָ��ʲô�ط�
	char* pc = &a;//���棡��������ͣ�ȡ����ʱֻ��char����ȡ
	short* ps=NULL;//��ָ�룬��ָ���κεط�
	float* pf=&a;//��������ͣ�ȡ����ʱ��float��ʽ��������Щ������λ
	double* pd=NULL;
	printf("%d,%d,%d,%d,%d,%d\n",
		   sizeof(int*), sizeof(char*), sizeof(short*),
		   sizeof(float*), sizeof(double*), sizeof(date*));
	printf("%p,%p,%p,%p,%p,%p\n", pi, pc, ps, pf, pd, pdate);
	printf("%x, %x\n", *pc, *pi);
	printf("%f\n", *pf);
	printf("%d\n", (*pdate).y);//��Ұָ����Ϊ��ַ�ұ�������ȫ
	date today={2010,7,21};
	pdate = &today;
	printf("%d\n", (*pdate).y);
	return 0;
}
