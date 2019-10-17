#include <string.h>
#include <stdio.h>

void mycopy(char * from, char * to)
{
    int i = 0;
    while( from[i] != '\0')
    {
        to[i] = from[i];
        i++;	
    }	    
}

int main()
{
    char str1[100] = {""};
    char str2[100] = {""};

    printf("Please input str1:\n");
    scanf("%s", str1);

    mycopy(str1, str2);

    printf("str2 is %s\n", str2);

    return 0;

}


