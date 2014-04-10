#include <stdio.h>
#include "my.h"
//extern int y;因为y在b.c中定义成static，不允许跨文件使用
void sfunc();
int main()
{
	printf("x=%d\n", x);
//	printf("y=%d\n", y);
	func();
	//sfunc();因为sfunc在b.c中定义成static的，不允许跨文件使用
	return 0;
}
