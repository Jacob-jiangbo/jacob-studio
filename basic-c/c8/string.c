#include <stdio.h>
//this function ��Ҫ֪ʶ��
//const char * p ; pΪ�۲�ָ�� �� ����������ƶ������ǵ�ǰ��ָ�ı����������ƶ�
//char * const r ; r�Ƕ���ָ�� ��ֻ�۲�һ��λ��
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
	//*p = 'F';���ܻᵼ�¶δ���
	const char* q = "furong";//q�ǹ۲�ָ��
	//char const* q��ͬ��const char* q
	printf("%s\n", q);
	//*q = 'F';����ʱ���ܹ������������
	q = "yangqiang";
	printf("%s\n", q);
	char* const r = name;//r�Ƕ���ָ�룬name<==>&name[0];
	//r = "furong";����ʱ������
	*r = 'C';
	printf("%s, %s\n", name, r);
	return 0;
}
