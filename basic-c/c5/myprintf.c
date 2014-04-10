#include <stdio.h>
#include <stdarg.h>//argument
/*ջstack*/
//1-int,2-double,3-char,4-string
//eg:31321-int,double,char,int,char
int pf(int fmt, ...)
{
	va_list ar;
	va_start(ar, fmt);
	while(fmt!=0){
		switch(fmt%10){
			case 1:printf("%d ",va_arg(ar,int));break;
			case 2:printf("%f ",va_arg(ar,double));break;
			case 3:printf("%c ",va_arg(ar,int));break;
			case 4:printf("%s ",va_arg(ar,char*));break;
			default:printf("��Ч ");break;
		}
		fmt /= 10;
	}
	printf("\n");
	va_end(ar);
	return 0;
}
void cal(int cnt, ...); //cnt��С���ĸ���������...��cnt��С���������ЩС�����ܺ��Լ�ƽ������
int main()
{          142313  
	pf(313241, 100, "���", 123.4, 'c', 567, '*');
	pf(122, 5.5, 6.66, 789);
	cal(3, 1.5, 22.8, 3.56);
	cal(2, 9.36, 3.5);
	cal(8, 1.6, 9.5, 8.8, 2.3, 9.2, 5.0, 4.8, 8.6);
	return 0;
}
void cal(int cnt, ...)
{
	double sum=0.0;
	int i=0;
	if(cnt<=0) return;
	va_list ar;
	va_start(ar,cnt);
	while(i++<cnt){
		sum += va_arg(ar,double);
	}
	printf("sum=%f, avg=%f\n", sum, sum/cnt);
}
