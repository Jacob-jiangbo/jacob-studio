#include <stdio.h>

void f1(){printf("���ǿɰ���f1\n");}
void f2(){printf("����������f2\n");}
void func(void(*f)())
{
	printf("���ݹ����ĺ�����ַ��%p\n", f);
	(*f)();
	printf("bye\n");
}
int main()
{
	printf("&main=%p, &f1=%p, &f2=%p\n", &main, &f1, &f2);
	char c;
	printf("1--f1, 2--f2:");
	scanf(" %c", &c);
	func(c=='1'?&f1:&f2);
	return 0;
}
