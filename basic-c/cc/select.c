//����N-1�Σ���i��0��<N-1��
//����С��δ�����ݸ���һ��δ�����ݽ�������Ϊ�������ݣ�
//	δ�������±��i��N-1
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
