#include <stdio.h>
int main()
{
	double sum,data;
	int i, n;
	puts("������ѧ������:");
	while(scanf("%d", &n)!=1||n<1){
		char c;
		puts("��Ч���룬������!");
		do scanf("%c",&c); while(c!='\n');
	}
	printf("������%d��ѧ���ĳɼ�:\n", n);
	i=0;
	sum=0.0;
	do{
		scanf("%lf", &data);
		sum += data;
		++i;
	}while(i<n);
	printf("ƽ���ɼ�:%g\n", sum/n);
	return 0;
}

