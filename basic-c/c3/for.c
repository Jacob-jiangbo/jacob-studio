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
	for(i=0,sum=0.0;i<n;i++)
	{
		if(scanf("%lf", &data)!=1||data<0||data>100){
			char c;
			puts("��Ч�ɼ���������!");
			do scanf("%c",&c); while(c!='\n');
			i--;
			continue;//����ʣ���ѭ���壬ѭ������
		}
		sum += data;
	}
	printf("ƽ���ɼ�:%g\n", sum/n);
	return 0;
}

