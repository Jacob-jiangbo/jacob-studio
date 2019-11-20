#include <stdio.h>


void sort(int a[], int n)
{	
        register int swap;
	register int i;
	--n;
	do{
		swap = 0;
		for(i=0; i<n; i++){
			if(a[i+1]<a[i])
                        {
				int t = a[i+1];
				a[i+1] = a[i];
                                a[i] = t;
                                swap++;
                        }
		}			
        }while(swap > 0);
} 

// More official qsearch , it could check if this num not in  array
int qsearch(int *a, int num, int cnt)
{
    int i = 0;
    int j = cnt - 1;
    int mid;

    while(i<=j)
    {
        mid = (i+j)/2;
	if( num == a[mid] )
	{
	    return mid;
	    break;
	}    
        else if(num > a[mid])
	    i = mid + 1;
	else
	    j = mid -1;
    }	    

    if(i>j) return 0;

}	


int binary_search(int s[], int x, int low, int high)
{
    if(low > high) return -1;

    int middle = (low + high)/2;
    printf("middle is %d\n", middle);
    if(x == s[middle]) 
    {
        return middle;
    }
    else if(x > s[middle])
    {
        return binary_search(s, x, middle+1, high);
    }else
    {
        return binary_search(s, x, low, middle-1);
    }
}

void list(int A[], int num)
{
    int i=0;
    while(i<num)
    {
        printf("%d, ", A[i++]);
    }
    printf("\n");
}

int main()
{
    int A[6]={6,2,7,1,5,3};
    list(A, 6);
    sort(A, 6);
    list(A, 6);

    printf("index for 6 is  %d\n", binary_search(A, 6, 0, 5));

    return 0;
}


