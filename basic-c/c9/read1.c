#include <stdio.h>
typedef struct student{
	char name[20];	
	int date[3];
	double score[5];
}student;
	
int main()
{
	FILE* f2 = fopen("file2", "r");
	if(NULL==f2)
	{	perror("fopen");	
		return 1;
	}
	int n;
	double d;
	char c;
	char str[100];
	char c1, c2, c3;
	student m;
//	fscanf(f2, "%d%lf %c%s", &n, &d, &c, str);
	fscanf(f2, " %c", &c1);
	putchar(c1);
	ungetc(c1, f2);
	c2 = fgetc(f2);
	printf("%c", c2);
	return 0;
}

