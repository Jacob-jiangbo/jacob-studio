#include <stdio.h>
#include <unistd.h>
#include <pcap/pcap.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void ifprint(pcap_if_t* d);
void iptoa(u_long in);
int main()
{	
	pcap_if_t* alldev;
	pcap_if_t* d;
	int i =0;
	char errbuf[PCAP_ERRBUF_SIZE];
	if(pcap_findalldevs(&alldev, errbuf)==-1)
	{	fprintf(stdout, "%s\n", errbuf);
		exit(1);
	}
	for(d=alldev; d; d=d->next)
	{	printf("%d : %s\n", i++, d->name);
		if(d->description)
			printf("%s\n", d->description);
		else
			printf("no descriptions\n");
		ifprint(d);
	}
	if(i==0)
	{
		printf("no interface fount\n");
	}
	pcap_freealldevs(alldev);
	return 0;
}

void ifprint(pcap_if_t* d)
{	pcap_addr_t *a;
	for(a=d->addresses; a; a = a->next)
	{	printf("Address family:#%d\n", a->addr->sa_family);
		switch(a->addr->sa_family)
		{	case AF_INET:
				printf("Address family is AF_INET\n");
				if(a->addr)
	//				printf("\tAddress: %s",
						iptoa(((struct sockaddr_in*)a->addr)->sin_addr.s_addr);
					break;			
			default:
				printf("Address family unknow\n");		
				break;
		}
	}
}

void iptoa(u_long in)
{	int i;
	for(i=0; i<4; i++)
	{	if(i<3)
			printf("%d.", ((u_char*)&in)[i]);
		else
			printf("%d", ((u_char*)&in)[i]);
	}
		printf("\n");
	return ;
}

