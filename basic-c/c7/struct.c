#include <stdio.h>
#include "person.h"

void show(person p)
{
	printf("��Һã�����%s���귽%d�Ĵ�%s������%g���ܸ�����ʶ��!\n",
		   p.name, p.age, p.gender?"˧��":"��Ů", p.salary);
}
void showa(person* p)
{
	printf("��Һã�����%s���귽%d�Ĵ�%s������%g���ܸ�����ʶ��!\n",
		   (*p).name, (*p).age, (*p).gender?"˧��":"��Ů", (*p).salary);
}
person input()
{
	printf("�������������Ա�(M/F)������͹���:\n");
	person p;
	char sex;
	scanf("%s %c%d%lf",p.name,&sex,&p.age,&p.salary);
	p.gender = (sex=='M'||sex=='m');
	return p;
}
int main()
{
	struct Person p1;//p1��һ���ṹ����
	struct Person p2={"ܽ��",false,18,8000};
	struct Person p3=
	{name:"Ȩ��",age:20,salary:2000,gender:true};
	person p4={"��ǿ",true,21,2500};
	person p5=p2;
	p1 = p3;
	show(p2);show(p4);showa(&p3);showa(&p5);showa(&p1);
	p5 = input();
	show(p5);
	show(input());
	return 0;
}
