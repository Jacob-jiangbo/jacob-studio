#include <stdio.h>
typedef struct date{
	int y;
	int m;
	int d;
}date;
int main()
{
	int a=0x78654321;
	int* pi = &a;//正确指向a
	date* pdate;//野指针，没准儿指向什么地方
	char* pc = &a;//警告！错误的类型，取变量时只按char类型取
	short* ps=NULL;//空指针，不指向任何地方
	float* pf=&a;//错误的类型，取变量时按float格式来解释那些二进制位
	double* pd=NULL;
	printf("%d,%d,%d,%d,%d,%d\n",
		   sizeof(int*), sizeof(char*), sizeof(short*),
		   sizeof(float*), sizeof(double*), sizeof(date*));
	printf("%p,%p,%p,%p,%p,%p\n", pi, pc, ps, pf, pd, pdate);
	printf("%x, %x\n", *pc, *pi);
	printf("%f\n", *pf);
	printf("%d\n", (*pdate).y);//用野指针作为地址找变量不安全
	date today={2010,7,21};
	pdate = &today;
	printf("%d\n", (*pdate).y);
	return 0;
}
