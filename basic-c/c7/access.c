#include <stdio.h>

typedef struct person{
	char name[20];
	int age;
	double salary;
}person;
void addsalary(person* x, double add)
{
	//(*x).salary += add;
	x->salary += add;
}
int main()
{
	person a={"‹Ω»ÿ",18,8000};
	person* p = &a;
	(*p).age += 2;
	addsalary(&a, 1000);
	printf("%s:%d,%f\n", a.name, a.age, a.salary);
	return 0;
}
