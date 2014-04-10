#include <stdio.h>

int main()
{
	int apple;
	printf("请输入苹果的数量:");
	scanf("%d", &apple);
	while(apple>0)
	{
		printf("装一箱%d苹果\n", apple>=20?20:apple);
		apple -= 20;
	}
	return 0;
}

