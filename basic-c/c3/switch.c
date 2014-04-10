#include <stdio.h>
int main()
{
	puts("a--java");
	puts("b--c++");
	puts("c--嵌入式");
	puts("d--数据库");
	puts("e--测试");
	puts("q--退出");
	printf("请选择:");
	char choice;
	scanf(" %c", &choice);
	if(choice=='q'){
		puts("谢谢光临");
	}
	else
	{
		switch(choice)
		{
			case 'a':
				puts("介绍java班的情况");break;
			case 'b':
				puts("介绍C++班的情况");break;
			case 'c':
				puts("介绍嵌入式班的情况");break;
			case 'd':
				puts("介绍数据库班的情况");break;
			case 'e':
				puts("介绍测试班的情况");break;
			default:
				puts("无效的选择");break;
		}
	}
	return 0;
}

