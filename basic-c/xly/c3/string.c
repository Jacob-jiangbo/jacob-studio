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
	printf("%s\n", a);//jsd1006,good����������β��
	a[8] = '\0';
	printf("%s\n", a);//jsd1006,
	a[3] = 0;
	printf("%s\n", a);//jsd
	printf("%s\n", a+1);//sd
	printf("%s\n", a+9);//ood����������β��
	char name[] = "chenzongquan";
	printf("%s\n", name);
	printf("%d\n", sizeof(name));
	printf("%d\n", strlen(name));
	printf("������һ���ַ���(����10���ַ��Ϳ��ܻ��ƻ�������������):\n");
	char str[10];
	scanf("%s", str);
	printf("str=(%s)\n", str);
	printf("name=(%s)\n", name);
	return 0;
}

