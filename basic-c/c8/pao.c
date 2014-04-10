#include <stdio.h>
#define SWAP(a,b) int (t) = (a);(a)=(b);(t)=(a)
int main()
{	int i, j;
	int a[5] = {1, 2, 3, 4, 5};
	for(i=0; i<5; i++)
	{	for(j=0; j<4; j++)
		{	if(a[i+j]<a[j+i+1])
				SWAP(a[i+j], a[j+i+1]);
		}
	}
	return 0;
}

