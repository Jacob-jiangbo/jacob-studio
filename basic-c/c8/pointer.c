#include <stdio.h>

typedef char* str;
int main()
{
	char c = '$';
	char h = '#';
	char* a, b;//a��char*����b��char
	a = &c;
	//b = &c;���棡��ַ��ֵ��char
	str p, q;//p��q����char*
	p = &c;
	q = &c;
	printf("&c=%p, &*p=%p\n", &c, &*p);
	*p = '@';
	printf("c=%c, *p=%c\n", c, *p);
	p = &h;
	printf("c=%c, h=%c, *p=%c\n", c, h,*p);
	printf("&c=%p, &h=%p, q=%p, p=%p\n", &c, &h, q, p);
	//char t=c;c=h;h=t;
	//char* t=q;q=p;p=t;���󷽷�
	char t=*p; *p=*q; *q=t;
	printf("c=%c, h=%c\n", c, h);
	return 0;
}
