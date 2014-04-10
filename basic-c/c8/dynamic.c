/*
void* malloc(字节数),成功返回申请的内存开始地址，失败返回NULL
void free(地址),释放内存空间，必须是动态申请的内存空间的地址

void*calloc(元素个数，每个元素的字节数),为数组申请空间，会清零
void*realloc(旧动态内存地址，新字节数),释放旧空间，申请新空间，会把旧空间中的数据复制到新空间中
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* p1 = (int*)malloc(sizeof(int));
	*p1 = 100;
	int* p2 = calloc(10, sizeof(int));
	if(NULL==p2){
		return 1;
	}
	int i;
	for(i=0; i<10; i++)
		p2[i] = 50+i;
	p2 = realloc(p2, 15*sizeof(int));
	printf("*p1=%d\n", *p1);
	for(i=0; i<15; i++)
		printf("%d ", p2[i]);
	printf("\n");
	free(p1); p1=NULL;
	free(p2); p2=NULL;
	return 0;
}
