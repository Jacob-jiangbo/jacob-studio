#include <stdio.h>
int main()
{
	puts("1--一级人才5000");
	puts("2--二级人才3000");
	puts("3--三级人才2000");
	puts("4--四级人才1000");
	puts("5--五级人才免费");
	puts("0--退出");
	printf("请选择:");
	int ch;
	if(scanf(" %d", &ch)!=1)
		puts("没有成功输入!");
	printf("ch=%d\n", ch);
	if(ch==0) puts("欢迎下次再来");
	else{
		switch(ch){
			case 1:puts("请付5000元");break;
			case 2:puts("请付3000元");break;
			case 3:puts("请付2000元");break;
			case 4:puts("请付1000元");break;
			case 5:puts("免费");break;
			default:puts("无效选择");break;
		}
	}
	return 0;
}

