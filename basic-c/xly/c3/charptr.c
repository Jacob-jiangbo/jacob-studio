#include <stdio.h>

int main()
{
	char name[]="chenzongquan";
	char* p = name;//p��������ַ�'c'�ĵ�ַ
	int i;
	for(i=0; i<5; i++)
		printf("%s\n", p+i);
	p = "jsd1006";//p��������ַ�'j'�ĵ�ַ
	printf("%s\n", p);
	//*p = 'J';���ܻᵼ�¶δ���
	//printf("%s\n", p);
	//scanf("%s", p);���ܻᵼ�¶δ���
	char* r = NULL;//��ָ��r��NULL����0���������κ�һ�������ĵ�ַ
	//char* q;//Ұָ��q�����汣�����һ������Ԥ֪�ĵ�ַ
	//scanf("%s", q);//����һ���ַ������浽q��ʾ�ĵ�ַȥ��������������
	char* x[5]={"abc","defghi","ha ha","lalala","k"};
	for(i=0; i<5; i++)
		printf("%s\n", x[i]);//puts(x[i]);
	return 0;
}

