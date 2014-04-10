#include <stdio.h>

int global=100;
int count()
{
	static int cnt=0;
	++cnt;
	return cnt;
}
int main()
{
	int local=200;
	printf("%p\n", &global);
	printf("%p\n", &local);
	static int sloc;
	printf("sloc=%d, addr:%p\n", sloc, &sloc);
	printf("%d\n", count());
	printf("%d\n", count());
	printf("%d\n", count());
	return 0;
}
