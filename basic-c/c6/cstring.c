#include <stdio.h>

int main()
{
	int i;
	char a[10]={'g','o','o','d',' ','l','u','c','k','!'};
	printf("%s\n", a);//������ܻ�������
	printf("size:%d\n", sizeof("gsd1006"));//8,��Ϊĩβ��'\0'
	for(i=0; i<8; i++)
		printf("%c,", "gsd1006"[i]);
//	printf("\n");
	//"gsd1006"[0] = 'G';�������
	a[7] = '\0';//0;
	a[2] = 0;
	for(i=0; i<5; i++)
		printf("%s\n", a+i);//good lu����һ������������
	for(i=0; i<5; i++)
		printf("%s\n", "gsd1006"+i);//good lu����һ������������
	return 0;
}
