#include <string.h>
#include <stdio.h>

int main()
{
	int x;
	char a[12]={'j','s','d','1','0','0','6',',','g','o','o','d'};
	int y;
	int i;
	for(i=0; i<12; i++)
	{
		printf("(%c)", a[i]);
	}
	printf("\n");
	printf("%s\n", a);//jsd1006,good可能有乱码尾随
	a[8] = '\0';
	printf("%s\n", a);//jsd1006,
	a[3] = 0;
	printf("%s\n", a);//jsd
	printf("%s\n", a+1);//sd
	printf("%s\n", a+9);//ood可能有乱码尾随
	char name[] = "chenzongquan";
	printf("%s\n", name);
	printf("%d\n", sizeof(name));
	printf("%d\n", strlen(name));
	printf("请输入一个字符串(超过10个字符就可能会破坏其它变量数据):\n");
	char str[10];
	scanf("%s", str);
	printf("str=(%s)\n", str);
	printf("name=(%s)\n", name);
	return 0;
}

