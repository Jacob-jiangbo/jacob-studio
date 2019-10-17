#include <stdio.h>
#include <string.h>

char* revert_string(char * str)
{
    int num = strlen(str);

    char * ptr = str;
    char * ptr_1 = str + num - 1;

    while(ptr < ptr_1)
    {
        char c = *ptr;
	* ptr = * ptr_1;
	* ptr_1 = c;
	++ ptr;
	-- ptr_1;
    }	    

    return str;
}

int main()
{	
    char str[65535];	
    int num;
    printf("Please inut one string:\n");
    scanf("%s", str);
    printf("revert string is %s\n", revert_string(str));
}	


