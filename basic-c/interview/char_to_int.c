#include <string.h>
#include <stdio.h>

int char_to_int(char * str)
{
   int i = 0;	
   int count = 0;
   while( str[i] != '\0')
   {
       count = count * 10 + ( str[i++] - '0');
   }   	   
   return count;
}

int main()
{
   char str[100] = {""};
   int num = 0;
   printf("Please input str:\n");
   scanf("%s", str);

   num = char_to_int(str);
   printf("%d\n", num);

   return 0;

}

