#include <stdio.h>

int main()
{
	int apple;
	printf("������ƻ��������:");
	scanf("%d", &apple);
	while(apple>0)
	{
		printf("װһ��%dƻ��\n", apple>=20?20:apple);
		apple -= 20;
	}
	return 0;
}

