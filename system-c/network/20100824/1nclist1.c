#include "pcap.h"
#include <sys/socket.h>
#include <netinet/in.h>

void ifprint(pcap_if_t *d);
char *iptos(u_long in);

int main()
{
	pcap_if_t *alldevs;
	pcap_if_t *d;
	char errbuf[PCAP_ERRBUF_SIZE+1];

	if (pcap_findalldevs(&alldevs, errbuf) == -1)
	{
		fprintf(stderr,"Error in pcap_findalldevs: %s\n",errbuf);
		exit(1);
	}

	for(d=alldevs;d;d=d->next)
	{
		ifprint(d);
	}
	return 1;
}

/* Print all the available information on the given interface */
void ifprint(pcap_if_t *d)
{
    pcap_addr_t *a;
    /* Name */
    printf("%s\n",d->name);
    /* Description */
    if (d->description)
    printf("\tDescription: %s\n",d->description);
    /* Loopback Address*/
    printf("\tLoopback: %s\n",(d->flags&PCAP_IF_LOOPBACK)?"yes":"no");
    /* IP addresses */
    for(a=d->addresses; a; a=a->next) 
    {
        printf("\tAddress Family: #%d\n",a->addr->sa_family);
        /* sockaddr_in */
        switch(a->addr->sa_family)
        {
            case AF_INET:
                printf("\tAddress Family Name: AF_INET\n");//
                if (a->addr)// IP
                    printf("\tAddress: %s\n",
                        iptos(((struct sockaddr_in *)a->addr)->sin_addr.s_addr));
                if (a->netmask)//
                    printf("\tNetmask: %s\n",
                        iptos(((struct sockaddr_in *)a->netmask)->sin_addr.s_addr));
                if (a->broadaddr)//
                    printf("\tBroadcast Address: %s\n",
                        iptos(((struct sockaddr_in*)a->broadaddr)->sin_addr.s_addr));
				printf("\tbame%d.%d.%d.%d\n", 
((unsigned char*)(&(((struct sockaddr_in*)a->netmask)->sin_addr.s_addr)))[0],
((unsigned char*)(&(((struct sockaddr_in*)a->netmask)->sin_addr.s_addr)))[1],
((unsigned char*)(&(((struct sockaddr_in*)a->netmask)->sin_addr.s_addr)))[2],
((unsigned char*)(&(((struct sockaddr_in*)a->netmask)->sin_addr.s_addr)))[3]

);
                break;
            default:
                printf("\tAddress Family Name: Unknown\n");
                break;
        }
		
    }
    printf("\n");
}

#define IPTOSBUFFERS 12
char *iptos(u_long in)
{
	static char output[IPTOSBUFFERS][3*4+3+1];
	static short which;
	u_char *p;
	p = (u_char *)&in;
	which = (which + 1 == IPTOSBUFFERS ? 0 : which + 1);
	sprintf(output[which], "%d.%d.%d.%d", p[0], p[1], p[2], p[3]);
	return output[which];
}
