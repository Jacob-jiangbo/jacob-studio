#include <stdio.h>
//this function 主要知识点
//const char * p ; p为观察指针 ， 可以随意的移动，但是当前所指的变量不可以移动
//char * const r ; r是定向指针 ，只观察一个位置
int main()
{
	char name[20]="chenzongquan";
	printf("%s\n", name+8);
	char* p = name;
	printf("%s\n", p);
	printf("input a string:");
	scanf("%s", p);
	printf("%s\n", name);
	p = "furong";
	printf("p=%p, furong at %p\n", p, "furong");
	//*p = 'F';可能会导致段错误
	const char* q = "furong";//q是观察指针
	//char const* q等同于const char* q
	printf("%s\n", q);
	//*q = 'F';编译时就能够发现这个错误
	q = "yangqiang";
	printf("%s\n", q);
	char* const r = name;//r是定向指针，name<==>&name[0];
	//r = "furong";编译时不允许
	*r = 'C';
	printf("%s, %s\n", name, r);
	return 0;
}
