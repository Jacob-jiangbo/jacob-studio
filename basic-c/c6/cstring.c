#include <stdio.h>

int main()
{
	int i;
	char a[10]={'g','o','o','d',' ','l','u','c','k','!'};
	printf("%s\n", a);//后面可能会有乱码
	printf("size:%d\n", sizeof("gsd1006"));//8,因为末尾有'\0'
	for(i=0; i<8; i++)
		printf("%c,", "gsd1006"[i]);
//	printf("\n");
	//"gsd1006"[0] = 'G';编译错误
	a[7] = '\0';//0;
	a[2] = 0;
	for(i=0; i<5; i++)
		printf("%s\n", a+i);//good lu后面一定不会有乱码
	for(i=0; i<5; i++)
		printf("%s\n", "gsd1006"+i);//good lu后面一定不会有乱码
	return 0;
}
