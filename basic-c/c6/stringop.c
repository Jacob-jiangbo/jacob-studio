#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char x='#';
	char str[300];
	char y='$';
	printf("请输入一个字符串:");
	//scanf("%s", str);//输入遇到空白字符截止
	//gets(str);//读取一整行，但编译有警告
	scanf("%[^\n]", str);//连续读取字符直到换行符\n之前
	printf("str=%s\n", str);
	printf("x=%c, y=%c\n", x, y);
	char s2[100] = {"大家好!"};//大括号可以不用写
	printf("%s\n", s2); 
	printf("%s\n", s2+1);//一般来说，这里输出会是乱码(半个汉字)
	//str = s2;
	strcpy(str, s2);//strcpy(到, 从)
	printf("str=%s\n", str);
	strcat(str, "才是真的好!");//strcat(串, 尾巴)
	printf("str=%s\n", str);
	printf("字符数组长度:%d, 字符串长度%d\n",sizeof(str),strlen(str));
	printf("%d\n", strcmp(s2,"大家好!"));//内容相同，0
	printf("%d\n", strcmp("hello","world"));//左小，负数
	printf("%d\n", strcmp("hello","everyone"));//左大，正数
	printf("%s\n", strchr("everyone",'y'));
	printf("%p\n", strchr("everyone",'z'));//NULL(nil)
	printf("%s\n", strstr("everyone","ery"));
	printf("%p\n", strstr("everyone","abc"));//NULL(nil)
	strcpy(s2, "1234.56");
	printf("%d, %f\n", atoi(s2), atof(s2));
	
	return 0;
}
