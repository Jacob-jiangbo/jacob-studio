#include <stdio.h>
#include <string.h>

int main()
{
	char strs[100]={"hello\0" "world\0" "good\0" "afternoon\0\0"};
	int i;
	for(i=0; strs[i]!='\0'; i+=strlen(strs+i)+1)
		printf("%s ", strs+i);
	printf("\n");
	char s[100]={"hello:everyone:nice:to:see:you:all"};
	for(i=0; s[i]; i++)
		printf("%c", s[i]==':'?' ':s[i]);
	printf("\n");
	printf("s[5]=%c(%d)\n",s[5],s[5]);
	char* p = strtok(s, ":");
	while(p!=NULL){
		printf("%s,", p);
		p = strtok(NULL, ":");
	}
	printf("\n");
	printf("s[5]=%c(%d)\n",s[5],s[5]);
	char path[] = "/usr/kerberos/bin:/opt/u01/oracle/product/9.2.0/bin:/opt/jdk/bin:/opt/mysql/bin:/opt/qt/bin:/usr/bin:/usr:/usr/sbin:/usr/local/bin:/usr/local/sbin:/bin:/sbin:.";
	char* a[20];
	a[0] = path;
	int j=1;
	i=0;
	while(path[i]){
		if(path[i]==':'){
			a[j++] = path+i+1;
			path[i] = 0;//'\0';
		}
		++i;
	}
	for(i=0; i<j; i++)
		printf("%s,", a[i]);
	printf("\n");
	return 0;
}
