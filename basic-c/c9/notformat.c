#include <stdio.h>
//非格式化标准IO：getchar/gets, putchar/puts
//ch=getchar();相当于scanf("%c",&ch);
//gets(buf);相当于scanf("%[^\n]%*c",buf);
//putchar(ch);相当于printf("%c",ch);
//puts(buf);相当于printf("%s\n",buf);
int main()
{
	printf("请输入一行字符:\n");
	char ch = getchar();
	char buf[100];
	gets(buf);//用scanf("%[^\n]%*c",buf)代替gets不会产生警告;
	printf("ch=[");putchar(ch);
	putchar(']');putchar('\n');
	printf("buf=[");puts(buf);putchar(']');putchar('\n');
	return 0;
}
