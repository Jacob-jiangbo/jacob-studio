#include <stdio.h>

void test(int x, int y)
{
	int t = x;
	x = y;
	y = t;
	printf("x=%d, y=%d\n", x, y);
}
typedef struct Person{
	char name[20];
	int age;
	double salary;
} Ps;
Ps input(void)
{
	Ps a;
	printf("����������������͹���:");
	scanf("%s %d %lf", &a.name, &a.age, &a.salary);
	return a;
}
void print(Ps p)
{
	printf("�ҽ�%s,����%d,��н%g\n", p.name,p.age,p.salary);
}
int main()
{
	int a=10;
	int b=a;
	printf("a�ĵ�ַ%p, b�ĵ�ַ%p\n", &a, &b);
	a += 5;
	b *= 8;
	printf("a=%d, b=%d\n", a, b);
	test(a, b);
	printf("a=%d, b=%d\n", a, b);
	Ps p;
	p = input();
	print(p);
	return 0;
}

