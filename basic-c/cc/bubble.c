//冒泡，快速，插入，选择
//反复多轮，每一轮：
//	依次比较所有相邻的数据对，如果顺序不适当就交换它们
//只要这一轮发生过交换就应该再来一轮，这一轮没有发生交换就排序完毕
void sort(int a[], int n)
{
	register int swap;
	register int i;
	do{
		--n;
		swap = 0;
		for(i=0; i<n; i++){
			if(a[i+1]<a[i]){
				int t=a[i+1];
				a[i+1]=a[i];
				a[i] = t;
				++swap;
			}
		}
	}while(swap>0);
}
