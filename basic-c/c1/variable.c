#include <stdio.h>
int main()
{
	int a = 123456;//定义并初始化
	int b;//定义但没有初始化，表示一个无法预知的数据（垃圾数据）
	printf("%d,%d\n",a,b);
	b = 789;
	a = 88888;
	printf("%d,%d\n",a,b);
	double salary = 2999.99;//2999.99F表示float类型，精确度低
	printf("工资%f\n", salary);
	char gender='M'/*'F'*/;//male,female
	printf("%c,%d\n",gender,gender);
	return 0;
}

