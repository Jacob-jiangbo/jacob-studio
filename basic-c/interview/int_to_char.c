#include <string.h>
#include <stdio.h>

void int_to_string(char * str, int num)
{
    int i = 0;	
    while(num > 0)
    {
        str[i++] = num % 10 + '0';
	num/=10;
	printf("%d\n", num);
    }	    

    int j;
    int k = 0;
    for(j=strlen(str) - 1; j>k; j--)
    {
        char c = str[j];
	str[j] = str[k];
	str[k] = c;
        k++;
    }	    
}



int main()
{
    int m;
    char c[100] = {""};
    printf("Please input a integer:\n");
    scanf("%d", &m);

    int_to_string(c, m);

    printf("Reverted string is %s \n", c);
}


