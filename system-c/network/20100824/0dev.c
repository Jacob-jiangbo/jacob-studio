#include <stdio.h>
#include <pcap.h>
int main()
{
	char *dev, errbuf[PCAP_ERRBUF_SIZE];
	dev = pcap_lookupdev(errbuf);//this dev can be pcap_open_live
	printf("Device: %s\n", dev);
	return(0);
}

