#include <stdio.h>
#include <time.h>
#include <math.h>

int main()
{	
	int pk[100] ={0};
	int i, j=0;
	for(i=0; i<100; i++)
		pk[i] = 1;
	int count=0, face;

	srand(time(NULL));
	while(count<108)
	{	for(i=0; i<108; i++)
		{
			face = rand()%54+1;
			if(pk[face]>0)
				{printf("%d,  ",face);
				 pk[face]--;
				 j++;
				}
		}
		count++;
	}
	printf("\n");
	printf("%d\n",j);
	return 0;
}
	
