#include <stdio.h>
//�Ǹ�ʽ����׼IO��getchar/gets, putchar/puts
//ch=getchar();�൱��scanf("%c",&ch);
//gets(buf);�൱��scanf("%[^\n]%*c",buf);
//putchar(ch);�൱��printf("%c",ch);
//puts(buf);�൱��printf("%s\n",buf);
int main()
{
	printf("������һ���ַ�:\n");
	char ch = getchar();
	char buf[100];
	gets(buf);//��scanf("%[^\n]%*c",buf)����gets�����������;
	printf("ch=[");putchar(ch);
	putchar(']');putchar('\n');
	printf("buf=[");puts(buf);putchar(']');putchar('\n');
	return 0;
}
