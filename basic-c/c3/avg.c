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
	while(i<n)
	{
		if(scanf("%lf", &data)!=1||data<0||data>100){
			char c;
			puts("��Ч�ɼ���������!");
			do scanf("%c",&c); while(c!='\n');
			continue;//����ʣ���ѭ���壬ѭ������
		}
		sum += data;
		++i;
	}
	printf("ƽ���ɼ�:%g\n", sum/n);
	return 0;
}

