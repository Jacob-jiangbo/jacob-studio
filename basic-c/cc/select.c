//反复N-1次（让i从0到<N-1）
//把最小的未序数据跟第一个未序数据交换（成为已序数据）
//	未序数据下标从i到N-1
void sort(int* a, int n)
{
	int i, j, min;
	for(i=0; i<n-1; i++){
		min = i;
		for(j=i+1; j<n; j++){
			if(a[j]<a[min]){
				min = j;
			}
		}
		int t=a[min];
		a[min]=a[i];
		a[i] = t;
	}
}
