#include <stdio.h>

int main()
{
	double a[5]={1.1,2.2,3.3,4.4,5.5};
	printf("a=%p\n", a);
	int i;
	for(i=0; i<5; i++)
		printf("&a[%d]=%p, a+%d=%p\n", i, &a[i], i, a+i);
	for(i=0; i<5; i++)
		printf("%g ", *(a+i));//a[i]==>*(a+i)
	printf("\n");
	for(i=0; i<5; i++)
		printf("%g ", i[a]);//i[a]==>*(i+a),½ö¹©ÓéÀÖ
	printf("\n");
	return 0;
}
