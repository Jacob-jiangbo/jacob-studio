#include <stdio.h>

int main(int argc)
{
	printf("argc=%d\n", argc);
	if(argc>0)
	{
		main(argc-1);
	}
	printf("��argc=%d����\n", argc);
	return 0;
}

