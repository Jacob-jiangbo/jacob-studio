#include <stdio.h>
#include "person.h"

void show(person p)
{
	printf("大家好，我是%s，年方%d的大%s，月入%g，很高兴认识你!\n",
		   p.name, p.age, p.gender?"帅哥":"美女", p.salary);
}
void showa(person* p)
{
	printf("大家好，我是%s，年方%d的大%s，月入%g，很高兴认识你!\n",
		   (*p).name, (*p).age, (*p).gender?"帅哥":"美女", (*p).salary);
}
person input()
{
	printf("请输入姓名、性别(M/F)、年龄和工资:\n");
	person p;
	char sex;
	scanf("%s %c%d%lf",p.name,&sex,&p.age,&p.salary);
	p.gender = (sex=='M'||sex=='m');
	return p;
}
int main()
{
	struct Person p1;//p1是一个结构变量
	struct Person p2={"芙蓉",false,18,8000};
	struct Person p3=
	{name:"权哥",age:20,salary:2000,gender:true};
	person p4={"杨强",true,21,2500};
	person p5=p2;
	p1 = p3;
	show(p2);show(p4);showa(&p3);showa(&p5);showa(&p1);
	p5 = input();
	show(p5);
	show(input());
	return 0;
}
