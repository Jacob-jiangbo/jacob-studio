#include <stdio.h>
int main()
{
	for(;;)
	{
		int y;
		printf("���������:");
		if(scanf("%d",&y)!=1) return 0;
		if(y==0) break;
		if(y<0) continue;
		if(y%4==0&&y%100!=0 || y%400==0)
			printf("%d������\n", y);
		else
			printf("%d��������\n", y);
	}
	printf("�ټ�\n");
	return 0;
}

