#include <stdio.h>
//#include <string.h>
#include <ctype.h>
int main()
{
	printf("������һ���ַ���:\n");
	char str[100];
	int alpha=0, num=0;
	int i;
	gets(str);//scanf("%s", str);
//	int len = strlen(str);
	for(i=0; str[i]!='\0'/*i<len*/; i++)
	{
		if(isdigit(str[i]))//str[i]>='0'&&str[i]<='9') 
			num++;
		else if(isalpha(str[i]))//str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z') 
			alpha++;
	}
	printf("��ĸ%d��������%d��\n", alpha, num);
	return 0;
}

