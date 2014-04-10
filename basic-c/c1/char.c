#include <stdio.h>

int main()
{
	printf("%c,%c,%c\n", 'a', 'ÄÐ', 65);
	printf("%d,%d,%d\n", 123, '1','1'-'0');
	printf("%d\n", 'ÄÐ');
	
	return 0;
}

