#include <stdio.h>

//把n个盘子从from位置移动到to位置，可以借用spare位置
void move(int n, char from, char to, char spare)
{
	//如果没有盘子，直接完活
	if(n==0) return;
	//把上面n-1个盘子从from位置临时移动到spare位置，可以借用to位置
	move(n-1, from, spare, to);
	//把第n个盘子直接从from位置移动到to位置
	printf("%d号盘子从%c位置到%c位置\n", n, from, to);
	//把spare位置上的n-1个盘子移动到to位置，可以借用from位置
	move(n-1, spare, to, from);
}

int main()
{
	move(10, 'A', 'B', 'C');
	return 0;
}
