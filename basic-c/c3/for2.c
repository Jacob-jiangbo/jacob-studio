#include <stdio.h>
int main()
{
	int i;
	int n;
	int sum=0;
	printf("请输入一个整数:");
	scanf("%d", &n);
	if(n<1) printf("不是素数，素数至少是2\n");
	else{
		int cnt=0;
		for(i=1; i<=n; i++){
			if(n%i==0){
				cnt++;
				sum += i;
			}
		}
		printf("%d%s素数\n",n,cnt==2?"是":"不是");
		printf("约数和为%d\n", sum-n);
	}
	
	return 0;
}

