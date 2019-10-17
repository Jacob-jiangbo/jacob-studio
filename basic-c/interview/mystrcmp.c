#include <stdio.h>
#include <string.h>
#include <assert.h>

int mycmp(char *str1, char *str2)
{
    int i = 0;	
    assert( str1 != 0 && str2 != 0);
    while( str1[i] == str2[i] && str1[i] != '\0')
    {
        i++;
    }	    
    
    printf("c1 is %c , c2 is %c\n", str1[i], str2[i]);

    if( str1[i] == '\0' && str2[i] == '\0' )
    {
       return 0;
    }	    
    else if(str1[i] > str2[i])
    {
       return 1;
    }
    else
    {
       return -1;
    }    

}

int main()
{
    char str1[100] = {""};
    char str2[100] = {""};
    printf("Please input str one:");
    scanf("%s", str1);
    printf("Please input str two:");
    scanf("%s", str2);

    int ret = mycmp(str1, str2);
    printf("ret is %d\n", ret);
    return 0;


}

