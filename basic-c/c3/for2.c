#include <stdio.h>
int main()
{
	int i;
	int n;
	int sum=0;
	printf("������һ������:");
	scanf("%d", &n);
	if(n<1) printf("��������������������2\n");
	else{
		int cnt=0;
		for(i=1; i<=n; i++){
			if(n%i==0){
				cnt++;
				sum += i;
			}
		}
		printf("%d%s����\n",n,cnt==2?"��":"����");
		printf("Լ����Ϊ%d\n", sum-n);
	}
	
	return 0;
}

