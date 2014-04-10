#include <stdio.h>

int isleap(int year);
int days(int year, int month);
int alldays(int year, int month, int day);

int main()
{
	int y, m, d;
	int sum;
	printf("请输入一个日期:");
	scanf("%d-%d-%d", &y, &m, &d);
	sum = alldays(y,m,d);
	printf("总共第%d天，星期%d\n", sum, sum%7);
	return 0;
}
int isleap(int year)
{
	return (year%4==0&&year%100!=0||year%400==0);
}
int days(int year, int month)
{
	if(month==4||month==6||month==9||month==11)
		return 30;
	if(month==2)
		return 28+isleap(year);
	return 31;
}
int alldays(int year, int month, int day)
{
	int y = year-1;
	int d, i;
	d = day + y*365+(y/4-y/100+y/400);
	for(i=1; i<month; i++)
		d += days(year,i);
	return d;
}
