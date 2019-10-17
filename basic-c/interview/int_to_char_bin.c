// Convert int to binary char

#include <stdio.h>


char* myitob(int num)
{
    // malloc point ok to be return	
    // static str are saved in head
    static char str[65535];
    char tmp[66635];
    int a, i=0, j=0;
    while(num > 0)
    {
        a = num%2;
        tmp[j++] = a + '0';
	num /= 2;
    }	   
    
    while(j>0)
    {
        str[i++] = tmp[--j];
    }	    

    str[i] = '\0';
    return str;

}


int main()
{
    int num;
    printf("Please input a int:\n");
    scanf("%d", &num);
    printf("%s\n", myitob(num));
    return 0;
}

