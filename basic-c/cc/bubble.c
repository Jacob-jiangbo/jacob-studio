//ð�ݣ����٣����룬ѡ��
//�������֣�ÿһ�֣�
//	���αȽ��������ڵ����ݶԣ����˳���ʵ��ͽ�������
//ֻҪ��һ�ַ�����������Ӧ������һ�֣���һ��û�з����������������
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
