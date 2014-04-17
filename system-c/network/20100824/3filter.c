#include <pcap.h>
 
#include <stdio.h>
int main()
{
	pcap_t *handle; /* �Ự��� */
	char *dev; /* ִ����̽���豸 */
	char errbuf[PCAP_ERRBUF_SIZE]; /* �洢������Ϣ���ַ��� */
	struct bpf_program filter; /* �Ѿ�����õĹ����� */
	char filter_app[] = "port 21"; /* ���˱��ʽ */
	bpf_u_int32 mask; /* ������������� */
	bpf_u_int32 net; /* ������IP��ַ */
	struct pcap_pkthdr header; /* ��pcap.h���� */
	const u_char *packet; /* ʵ�ʵİ� */
	/* Define the device */
	dev = pcap_lookupdev(errbuf);
	/* ̽���豸���� */
	pcap_lookupnet(dev, &net, &mask, errbuf);
	/* �Ի���ģʽ�򿪻Ự */
	handle = pcap_open_live(dev, BUFSIZ, 1, 0, errbuf);
	/* ���벢Ӧ�ù����� */
	pcap_compile(handle, &filter, filter_app, 0, net);
	pcap_setfilter(handle, &filter);
	/* �ػ�һ���� */
	packet = pcap_next(handle, &header);
	for(i=0; i<head->len; i++)
		if(isprintf(pkt_data[i]))
			printf("%c", pkt_data[i]);
	/* ��ӡ���ĳ��� */
	printf("Jacked a packet with length of [%d]\n", header.len);
	/* �رջỰ */
	pcap_close(handle);
	return(0);
}
