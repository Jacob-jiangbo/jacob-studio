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
	do{
		scanf("%lf", &data);
		sum += data;
		++i;
	}while(i<n);
	printf("平均成绩:%g\n", sum/n);
	return 0;
}

