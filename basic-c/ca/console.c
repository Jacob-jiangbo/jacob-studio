//stdin,stdout,stderr
#include <stdio.h>

int main()
{
	fprintf(stdout,"������һ��������һ��С��:\n");
	int n;
	double d;
	fscanf(stdin,"%d%lf", &n, &d);
	fprintf(stdout, "n=%d,", n);if(n>100)fflush(stdout);
	fprintf(stderr, "d=%f,", d);
	return 0;
}
