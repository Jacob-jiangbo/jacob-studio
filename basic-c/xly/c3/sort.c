# include<stdio.h>

int main()
{
	int a[11];
	int i,j,t;
	printf("please input 10 number:\n");
	for(i=1;i<11;i++)
		scanf("%d",&a[i]);
	printf("\n");
	for(j=1;j<10;j++)
	{
		for(i=1;i<=10-j;i++)
		{
			if(a[i]>a[i+1])
			{
				a[i]=a[i]^a[i+1];
				a[i+1]=a[i]^a[i+1];
				a[i]=a[i]^a[i+1];
			}
		}
		printf("the sorted numbers:\n");
		for(i=1;i<11;i++)
			printf("%d ",a[i]);

	}			
}
