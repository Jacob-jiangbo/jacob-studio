#include <stdio.h>

int alldigit(char a[])
{
	int i;
	for(i=0;a[i]/*!='\0'*/;i++){
		if(a[i]<'0'||a[i]>'9') 
			return 0;//false
	}
	return 1;//true
}
int main()
{
	char s[100];
	printf("input a string:");
	scanf("%s", s);
	printf("%d\n", alldigit(s));
	return 0;
}
