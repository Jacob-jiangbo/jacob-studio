#include <stdio.h>
#include <stdarg.h>//argument
/*栈stack*/
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
			default:printf("无效 ");break;
		}
		fmt /= 10;
	}
	printf("\n");
	va_end(ar);
	return 0;
}
void cal(int cnt, ...); //cnt是小数的个数，后面...是cnt个小数，输出这些小数的总和以及平均数。
int main()
{          142313  
	pf(313241, 100, "你好", 123.4, 'c', 567, '*');
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
