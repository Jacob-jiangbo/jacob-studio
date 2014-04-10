 #include <stdio.h>
int main()
{//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	char ch;
//menu:
	do{
		puts("1--一级人才5000");
		puts("2--二级人才3000");
		puts("3--三级人才2000");
		puts("4--四级人才1000");
		puts("5--五级人才免费");
		puts("0--退出");
		scanf(" %c", &ch);
//		char c;do{scanf("%c",&c);}while(c!='\n');
	}while((ch<'0'||ch>'5')&&printf("无效选择\n"));
//	if(ch<'0'||ch>'5') goto menu;
	printf("您选择的是%c\n", ch);
	return 0;
}
//;;;;;;;;;;;;;;;;;;;;;;;;;;

