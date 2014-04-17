#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
int main (int argc, char *argv[])
{
	struct hostent *h;
		/* ����������еĲ����Ƿ���� */
	if (argc != 2)
	{
		/* ���û�в���������ʹ�÷��� */
		fprintf (stderr,"usage: getip address\n");
		/* Ȼ���˳� */
		exit(1);
	}
		/* ȡ��������Ϣ */
	if((h=gethostbyname(argv[1])) == NULL)
	{
		/* ���gethostbyname ʧ�ܣ������������Ϣ */
		perror("gethostbyname");
		/* Ȼ���˳� */
		exit(1);
	}
	/* ��ӡ����ȡ�õ���Ϣ */
	printf("Host name : %s\n", h->h_name);
	printf("IP Address : %s\n", inet_ntoa (*((struct in_addr *)h->h_addr)));
	/* ���� */
	return 0;
}

