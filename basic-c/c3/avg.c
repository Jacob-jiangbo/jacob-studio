#include <stdio.h>
int main()
{
	double sum,data;
	int i, n;
	puts("请输入学生人数:");
	while(scanf("%d", &n)!=1||n<1){
		char c;
		puts("无效输入，请重试!");
		do scanf("%c",&c); while(c!='\n');
	}
	printf("请输入%d个学生的成绩:\n", n);
	i=0;
	sum=0.0;
	while(i<n)
	{
		if(scanf("%lf", &data)!=1||data<0||data>100){
			char c;
			puts("无效成绩，请重试!");
			do scanf("%c",&c); while(c!='\n');
			continue;//跳过剩余的循环体，循环依旧
		}
		sum += data;
		++i;
	}
	printf("平均成绩:%g\n", sum/n);
	return 0;
}

