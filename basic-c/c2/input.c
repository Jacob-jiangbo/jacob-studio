#include <stdio.h>
int main()
{
	char c;
	short s;
	int n;
	long L;
	float f;
	double d;
	char str[100];
	printf("������1���ַ�3������2��С����1���ַ���:\n");
	scanf("%c%hd%d%ld%f%lf%s",&c,&s,&n,&L,&f,&d,&str);
	printf("c=%c\n", c);
	printf("s=%d\n", s);
	printf("n=%d\n", n);
	printf("L=%d\n", L);
	printf("f=%f\n", f);
	printf("d=%f\n", d);
	printf("str=%s\n", str);
	return 0;
}

