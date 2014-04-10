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
double x=8888.8;//全局变量，默认初始化为数值0
//double x=8888.8;//全局变量，默认初始化为数值0
