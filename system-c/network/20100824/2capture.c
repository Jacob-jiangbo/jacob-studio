#include "pcap.h"

/* prototype of the packet handler */
void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char
*pkt_data);

int main()
{
	pcap_if_t *alldevs;
	pcap_if_t *d;
	int inum;
	int i=0;
	pcap_t *adhandle;
	char errbuf[PCAP_ERRBUF_SIZE];

	if (pcap_findalldevs(&alldevs, errbuf) == -1)
	{
		fprintf(stderr,"Error in pcap_findalldevs: %s\n", errbuf);
		exit(1);
	}

	for(d=alldevs; d; d=d->next)
	{
		printf("%d. %s", ++i, d->name);
		if (d->description)
			printf(" (%s)\n", d->description);
		else
			printf(" (No description available)\n");
	}
	if(i==0)
	{
		printf("\nNo interfaces found! Make sure WinPcap is installed.\n");
		return -1;
	}
	printf("Enter the interface number (1-%d):",i);
	scanf("%d", &inum); 
	if(inum< 1 || inum> i)
	{
		printf("\nInterface number out of range.\n");
		/* Free the device list */
		pcap_freealldevs(alldevs);
		return -1;
	}

	for(d=alldevs, i=0; i< inum-1 ;d=d->next, i++);
	if ( (adhandle= pcap_open_live(d->name, 65536, 1, 1000, errbuf)) == NULL)
	//promisc  specifies if the interface is to be put into promiscuous mode
	//to_ms specifies the read timeout in milliseconds
	{
		fprintf(stderr,"\nUnable to open the adapter. %s is not supported by Pcap\n");
		/* Free the device list */
		pcap_freealldevs(alldevs);
		return -1;
	}
	printf("\nlistening on %s...\n", d->description);
	/* At this point, we don't need any more the device list. Free it */
	pcap_freealldevs(alldevs);

	pcap_loop(adhandle, 0, packet_handler, NULL);
	return 0;
}

void packet_handler(u_char *param, const struct pcap_pkthdr * header, const u_char * pkt_data)
{
	struct tm * ltime;
	char timestr[16];

	ltime=localtime(&header->ts.tv_sec);
	//把从1970-1-1零点零分到当前时间系统所偏移的秒数时间转换为日历时间
	strftime( timestr, sizeof timestr, "%H:%M:%S", ltime);
	//函数功能：将时间格式化，或者说：格式化一个时间字符串。
	//size_t strftime(
　　	//	char *strDest,
　　	//	size_t maxsize,
　　	//	const char *format,
　　	//	const struct tm *timeptr
　　	//	); 
	//我们可以根据format指向字符串中格式命令把timeptr中保存的时间信息放在strDest指向的字符串中，
	//最多向strDest中存放maxsize个字符。该函数返回向strDest指向的字符串中放置的字符数。
	printf("%s,%.6d len:%d\n", timestr, header->ts.tv_usec, header->len);
}
