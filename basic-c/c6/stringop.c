#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char x='#';
	char str[300];
	char y='$';
	printf("������һ���ַ���:");
	//scanf("%s", str);//���������հ��ַ���ֹ
	//gets(str);//��ȡһ���У��������о���
	scanf("%[^\n]", str);//������ȡ�ַ�ֱ�����з�\n֮ǰ
	printf("str=%s\n", str);
	printf("x=%c, y=%c\n", x, y);
	char s2[100] = {"��Һ�!"};//�����ſ��Բ���д
	printf("%s\n", s2); 
	printf("%s\n", s2+1);//һ����˵�����������������(�������)
	//str = s2;
	strcpy(str, s2);//strcpy(��, ��)
	printf("str=%s\n", str);
	strcat(str, "������ĺ�!");//strcat(��, β��)
	printf("str=%s\n", str);
	printf("�ַ����鳤��:%d, �ַ�������%d\n",sizeof(str),strlen(str));
	printf("%d\n", strcmp(s2,"��Һ�!"));//������ͬ��0
	printf("%d\n", strcmp("hello","world"));//��С������
	printf("%d\n", strcmp("hello","everyone"));//�������
	printf("%s\n", strchr("everyone",'y'));
	printf("%p\n", strchr("everyone",'z'));//NULL(nil)
	printf("%s\n", strstr("everyone","ery"));
	printf("%p\n", strstr("everyone","abc"));//NULL(nil)
	strcpy(s2, "1234.56");
	printf("%d, %f\n", atoi(s2), atof(s2));
	
	return 0;
}
