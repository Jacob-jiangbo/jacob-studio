#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	char buf[100], ip[100];
	printf("¿¿¿¿¿IP¿");
	scanf("%s", buf);
	int addr = inet_addr(buf);
	for(int i=0; i<sizeof(addr); i++)
		printf("%d ", ((unsigned char*)&addr)[i]);
	printf("\n");
	struct in_addr ia;
	ia.s_addr = addr;
	printf("%s\n", inet_ntoa(ia));//inet_ntoa¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿ip¿¿¿
	return 0;
}

