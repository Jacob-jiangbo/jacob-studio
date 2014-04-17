#include <stdio.h>
#include "stdlib.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <sys/types.h>

/* ����tpc/ip���ݰ������ݽṹ */
struct ip_tcp {
    struct iphdr *iph;
    struct  tcphdr *tcph;
    unsigned char buffer[500];
};
/*
struct iphdr {
#if defined(__LITTLE_ENDIAN_BITFIELD)
    __u8    ihl:4,
            version:4;
#elif defined (__BIG_ENDIAN_BITFIELD)
    __u8    version:4,
            ihl:4;
#else
#error "Please fix <asm/byteorder.h>"
#endif
    __u8    tos;
    __be16 -tot_len;
    __be16 -id;
    __be16 -frag_off;
    __u8    ttl;
    __u8    protocol;
    __be16 -check;
    __be32 -saddr;
    __be32 -daddr;
};*/
int main()
{
	int sock, bytes_recieved, fromlen,n,id=1;
	unsigned char buffer[65535];
	struct sockaddr_in from,ff;
	struct ip  *ip;
	struct tcphdr *tcp;
	struct ip_tcp *iptcp;

	/* ����ԭʼTCP����ʽ �յ�IP+TCP��Ϣ�� */
	sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
	printf("IPPROTO_TCP= %d \n",IPPROTO_TCP);

	if (sock<=0) exit(0);

	id=1;
	while(1)
	{
		fromlen = sizeof(from);
		/* ���հ� */
		bytes_recieved = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *)&from, &fromlen);

		if ( bytes_recieved>0 )
		{
			printf("ok");
			/* IPͷΪ��С160λ 8λһ���ֽ� ��20���ֽ� ��0x14�� �� */
			/* Ϊ�������TCP��UDP����Ϣ */
			ip = (struct ip *)buffer;
			/* tcp��Ϣ�� ������IP/TCP�� buffer + (4*ip->ip_length) ��ַ����ʼ */
			tcp = (struct tcphdr *)(buffer + (4*ip->ip_hl));
			if ( ntohs(tcp->dest)!=23 )  /* ���Ը�Ϊ����(˵������ʾTELNET����Ϣ) */
			{
				printf("\n ID=::: %d\n",id);
				printf("Bytes received ::: %5d\n",bytes_recieved);
				printf("---- IP info begin ---- \n");
				printf("IP header length ::: %d\n",ip->ip_hl);
				printf("IP sum      size ::: %d\n",ntohs(ip->ip_len));
				printf("Protocol ::: %d\n",ip->ip_p);
				printf("IP_source address ::: %s \n",inet_ntoa(ip->ip_src));
				printf("IP_dest address ::: %s \n",inet_ntoa(ip->ip_dst));
				for (n=0;n<4*ip->ip_hl;n++)
				{
					printf("%02X ",buffer[n]);
				}
				printf("\n");
				printf("----  IP info end  ----  \n");
				printf("----TCP info begin ----  \n");
				/* ntohs  ����� short int תΪ���ص� short int  */
				printf("Source port ::: %d\n",ntohs(tcp->source));
				printf("Dest port  ::: %d\n",ntohs(tcp->dest));
				printf("Source address ::: %s\n",inet_ntoa(from.sin_addr));
				/* �г��յ���TCP��Ϣ���� һ��TCPͷ20���ֽ� */
				/* ����TCP��20���ֽ��Ǵ��͵���Ϣ */
				for (n=(4*ip->ip_hl+20);n<ntohs(ip->ip_len);n++)
				{
					printf("%c",buffer[n]);
					if (n>65)
					{
						break;
					}
				}
			  	printf("----TCP info end    ----  \n");
       	   		id=id+1;        
       	  	}  /*>23 end */
		} /*>0 end */
	} /*while end */
}	

