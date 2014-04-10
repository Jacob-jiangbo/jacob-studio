#include <stdio.h>
#include <stdlib.h>
/*
void qsort(开始地址，元素个数，元素的单位长度，比较函数)
比较函数：
int 函数名(const void* a, const void* b)
a和b分别是两个元素的地址。
如果元素顺序不需要交换，要返回负数；
如果元素顺序需要交换，要返回正数；
如果交换与否都无所谓，要返回0。
*/
typedef struct student{
	char name[20];
	int age;
	double score;
}student, *stuptr;

void input(student a[], int n)
{
	int i;
	for(i=0; i<n; i++){
		printf("请输入第%d个学生的姓名、年龄和成绩:",i+1);
		scanf("%s%d%lf",&a[i].name,&a[i].age,&a[i].score);
	}
}
void print(stuptr a, int n)
{//a->name == (*a).name == a[0].name
	int i;
	for(i=0; i<n; i++,a++)
		printf("%s:\t%d\t%g\n", a->name,a->age,a->score);
}
int nameasc(const void* a, const void* b)
{
	stuptr p=(student*)a, q=(stuptr)b;
	return strcmp(p->name,q->name);
}
int scoredsc(const void* a, const void* b)
{
	stuptr p=(stuptr)a, q=(stuptr)b;
	if(p->score > q->score) return -1;
	if(p->score < q->score) return 1;
	return 0;
}
int main()
{
	printf("请输入学生人数:");
	int n;
	scanf("%d", &n);
	stuptr /*const*/ p = calloc(n, sizeof(student));
	if(p==NULL){
		printf("申请内存空间失败!\n");
		return 1;
	}
	input(p, n);
	qsort(p, n, sizeof(student), nameasc);
	print(p, n);
	qsort(p, n, sizeof(student), scoredsc);
	print(p, n);
	//p++;free(p-1);
	free(p); p=NULL;//*(stuptr*)&p=NULL;printf("%p\n",p);
	return 0;
}
