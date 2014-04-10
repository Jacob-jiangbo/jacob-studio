#include <stdio.h>

int main()
{
	int i, j;//行号和列号
	int b, e;//星号位置
	int n;//边长
	//从键盘输入边长
	printf("请输入边长:");
	scanf("%d", &n);
	//反复2n－1次，每次打印一行
	for(i=1; i<2*n; i++)
	{
		//计算本行的星号位置
		b = (i<=n?(n-i+1):(i-n+1));
		e = 2*n - b;
		//反复2n－1次，每次打印一列
		for(j=1; j<2*n; j++)
		{
			//如果是星号位置就打星号，
			//if(j==b||j==e) printf("*");//打印空心菱形
			if(j>=b&&j<=e) printf("*");//打印实心菱形
			//否则就打空格
			else printf(" ");
		}
		//打印换行符
		printf("\n");
	}
	//完成
	return 0;
}

