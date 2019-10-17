#include <stdio.h>
#include <string.h>


//big endian int 1 save as  0 0 0 1 in char (normal order)
//little endian int as save as 1 0 0 0 in char 

void checkCPU()
{
    union w
    {
        int a;
	char b;
    }c;	    

    c.a = 1;
    c.b == 1 ? printf("little end\n") : printf("big end\n");

    return;

}

int main()
{
    checkCPU();
    return 0;
}	


