#include <stdio.h>
typedef struct{
	char name[20];
	char gender;//������3������ֽ�
	double salary;
	char married;//������3������ֽ�
}person;
int main()
{
	person p;
	printf("&p=%p\n", &p);
	printf("&p.name=%p\n", &p.name);
	printf("&p.name[0]=%p\n", &p.name[0]);
	printf("&p.gender=%p\n", &p.gender);
	printf("&p.salary=%p\n", &p.salary);
	printf("&p.married=%p\n", &p.married);
	printf("size:%d\n", sizeof(p));
	return 0;
}
