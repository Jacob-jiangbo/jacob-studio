#include <stdio.h>
#include <stdlib.h>//standard library headerfile

int main()
{
	printf("»¶Ó­Ê¹ÓÃ³Â×ÚÈ¨shell 1.0°æ\n");
	for(;;){
		char line[1000];
		printf("^o^ ");
		scanf(" %[^\n]", line);
		if(strcmp(line,"bye")==0)
			break;
		system(line);
	}
	return 0;
}

