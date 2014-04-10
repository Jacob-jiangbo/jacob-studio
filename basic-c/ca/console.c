//stdin,stdout,stderr
#include <stdio.h>

int main()
{
	fprintf(stdout,"请输入一个整数和一个小数:\n");
	int n;
	double d;
	fscanf(stdin,"%d%lf", &n, &d);
	fprintf(stdout, "n=%d,", n);if(n>100)fflush(stdout);
	fprintf(stderr, "d=%f,", d);
	return 0;
}
