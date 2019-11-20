
#include<stdio.h>
#include<string.h>
/*
*	从一长串字符串中找到最长的回文长度
*/
void main()
{
 	char s[50];
 	int i,l,max=0,k,j,locate;
 	printf("please input the string length <=50!:\n");
	scanf("%s",&s);
 	l=strlen(s);
 	for(i=1;i<l;i++)
 	{
  		for(k=i-1,j=i+1;k>=0&&s[k]==s[j];k--,j++);
  		if(i-k>max)
 		{
 			 max=(i-k)*2+1;locate=k+1;
  		}
 	}
	for(i=1;i<l;i++)
 	{
  		for(k=i-1,j=i;k>=0&&s[k]==s[j];k--,j++);
 		if(i-k>max)
  		{
  			max=(i-k)*2;locate=k+1;
  		}
 	}
	for(i=locate;i<locate+max-2;i++)
  	printf("%c",s[i]);
 	printf("\n");
}
