#include <stdio.h>

typedef struct Course{
	char name[50];
	int days;
} CS;
void print(const CS* p)//const��ʾͨ�������ַ�Ա�������ֻ������
{
	printf("%s:%d\n", (*p).name, (*p).days);
	printf("%s:%d\n", p->name, p->days);
	//p->days++;������󣺶Գ�ŵֻ����������ͼ�����޸�
}
int main()
{
	CS c={"C���Ի���",6};
	print(&c);
	print(&c);
	return 0;
}

