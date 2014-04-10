#include <stdio.h>
#include <string.h>
int main()
{
	char buf[100];
	sprintf(buf, "hello, %s! today is 星期%d\n", "各位", 5);
	buf[strlen(buf)-1] = '\0';
	strcat(buf, "!但不是周末^o^\n");
	printf("%s", buf);
	const char* str = "123 45.67 $"; //char str[]
	int n;
	float f;
	char ch;
	sscanf(str, "%d%f %c", &n, &f, &ch); 
	printf("n=%d, f=%g, ch=%c\n", n, f, ch);
	char const * file = "abc.avi";
	int k=15;
	char filename[100];
	int i;
	for(i=1; i<=15; i++){
		sprintf(filename, "%s.%03d", file, i);
		puts(filename);
	}
	return 0;
}
