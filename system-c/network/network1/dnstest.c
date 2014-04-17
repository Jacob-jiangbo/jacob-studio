#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
int main (int argc, char *argv[])
{
	struct hostent *h;
	if (argc != 2)
	{
		fprintf (stderr,"usage: getip address\n");
		exit(1);
	}
	if((h=gethostbyname(argv[1])) == NULL)
	{
		perror("gethostbyname");
		exit(1);
	}
	printf("Host name : %s\n", h->h_name);
	int j;
	for(j=0; j<4; j++)
		printf("%d  ", h->h_addr[j]);
	printf("\n");
	printf("IP Address : %s\n", inet_ntoa (*((struct in_addr *)h->h_addr)));
	char ip[100];
	//char ip1[100];
	int ip1;
	scanf("%s", ip);
//	ip1 = printf("%d\n", inet_addr(ip));
	ip1 = inet_addr(ip);
	int i;
	for(i=0; i<sizeof(ip1); i++)
		printf("%d ", ((unsigned char*)&ip1)[i]);
	printf("\n");
//	struct in_addr ia;
//	ia.s_addr = ip1;
	printf("%s\n", inet_ntoa(ip1));
	return 0;
}

