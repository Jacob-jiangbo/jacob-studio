#include <stdio.h>

#define MAX(a,b) (a>b?a:b)
#define GREATER(a,b) ((a)-(b)>0)
#define ISLEAP(y) ((y)%4==0&&(y)%100!=0||(y)%400==0)
#define DAYS(y,m) (((m)==4||(m)==6||(m)==9||(m)==11)?30:\
	(((m)!=2)?31:(ISLEAP((y))?29:28)))
#define CHECKDATE(y,m,d) ((y)>=1&&(m)>=1&&(m)<=12\
	&&(d)>=1&&(d)<=DAYS((y),(m)))
#define PDS(y,m) printf(#y "/" #m ":%d\n",DAYS(y,m))
#define PR(s,n) printf(#s" "#n" is %d\n", s##n)
int main()
{
	int student1=90, student2=95;
	int x=20, y=10;
	printf("%d\n", MAX(x,y)+30);
	printf("%d\n", GREATER(x,y+30));
	printf("%d\n", MAX(x++,y++));//调用宏函数时不要用++--
	printf("x=%d, y=%d\n", x, y);
	PDS(2010,7);//printf("2010/7:%d\n", DAYS(2010,7));
	PDS(2010,2);//printf("2010/2:%d\n", DAYS(2010,2));
	PDS(2012,2);//printf("2012/2:%d\n", DAYS(2012,2));
	PDS(2012,9);//printf("2012/6:%d\n", DAYS(2012,6));
	printf("%d\n", CHECKDATE(2010,2,29));
	printf("%d\n", CHECKDATE(2012,2,29));
	PR(student,1);
	PR(student,2);
}
