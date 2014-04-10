//如果数据个数不超过1个，直接完成
//如果是两个元素，就直接比较排序，完成
//取位置居中的元素作为分界值，
//把它跟第一个元素交换
//设置两个指针L和R分别指向第二个和最后一个元素
//反复，只要L和R不相遇
//	从左向右找比分界值不小的数据
//	从右向左找比分界值小的数据
//	如果没有相遇就交换这两个数据
//把分界值（第一个元素）跟从右向左找到的那个数据交换
//对左右两组各自再排序
#define swap(a,b) {int t=a;a=b;b=t;}
void sort(int* a, int n)
{
	if(n<=1) return;
	if(n==2){
		if(a[0]>a[1])
			swap(a[0],a[1]);
		return;
	}
	swap(a[0],a[n/2]);
	register int pivot=a[0];
	int* L=a+1;
	int* R=a+n-1;
	while(L<R){
		while(L<R&&*L<pivot) ++L;
		while(a<R&&*R>=pivot) --R;
		if(L<R)
			swap(*L,*R);
	}
	if(*R<*a)
		swap(*a,*R);
	sort(a,R-a);
	sort(R+1,n-1-(R-a));
}
