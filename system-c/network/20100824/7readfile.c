#include <stdio.h>
#include <pcap.h>

#define LINE_LEN 16

void dispatcher_handler(u_char *, const struct pcap_pkthdr *, const u_char *);

main(int argc, char **argv)
{
	pcap_t *fp;
	char errbuf[PCAP_ERRBUF_SIZE];
	
	if(argc != 2)
	{	
		printf("usage: %s filename", argv[0]);
		return -1;

	}
	
	/* Open the capture file */
	if ((fp = pcap_open_offline(argv[1],	// name of the device
					errbuf	// error buffer
						 )) == NULL)
	{
		fprintf(stderr,"\nUnable to open the file %s.\n", argv[1]);
		return -1;
	}

	/* read and dispatch packets until EOF is reached */
	pcap_loop(fp, 0, dispatcher_handler, NULL);

	pcap_close(fp);
	return 0;
}



void dispatcher_handler(u_char *temp1, 
			const struct pcap_pkthdr *header, 
			const u_char *pkt_data)
{
	u_int i=0;
	
	/* print pkt timestamp and pkt len */
	printf("%ld:%ld (%ld)\n", header->ts.tv_sec, header->ts.tv_usec, header->len);			
	
	/* Print the packet */
	for (i=1; (i < header->caplen + 1 ) ; i++)
	{
		printf("%.2x ", pkt_data[i-1]);
		if ( (i % LINE_LEN) == 0) printf("\n");
	}
	
	printf("\n\n");		
	
}
