#include <stdio.h>
#include "time.h"

int invalid(time p)
{
	return (p.hour>23||p.minute>59||p.second>59);
}
time inputtime()
{
	time t;
	do{
		printf("������ʱ��(hh mm ss):");
		scanf("%hd%hd%hd", &t.hour, &t.minute, &t.second);
	}while(invalid(t)&&printf("��Чʱ��!\n"));//do����while�������о�����ж����
	return t;
}
void print(time* p)
{
	printf("%s%d:%s%d:%s%d\n",
		   (*p).hour<10?"0":"",(*p).hour,
		   (*p).minute<10?"0":"",(*p).minute,
		   (*p).second<10?"0":"",(*p).second);
}
int main()
{
	time t = inputtime();
	print(&t);
	return 0;
}
