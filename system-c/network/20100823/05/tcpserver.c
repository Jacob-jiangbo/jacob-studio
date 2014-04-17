/* tcpServer.c */
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include "stdlib.h"
#include <unistd.h> /* close */
#define SUCCESS 0
#define ERROR   1
#define END_LINE 0x0A
#define SERVER_PORT 15009
#define MAX_MSG 100

/* ���庯�� readline */
int read_line();
int main (int argc, char *argv[]) 
{
  	int sd, newSd, cliLen;
  	struct sockaddr_in cliAddr, servAddr;
  	char line[MAX_MSG];

  	sd = socket(AF_INET, SOCK_STREAM, 0);
   	if(sd<0) 
	{
    		perror("cannot open socket ");
    		return ERROR;
  	}

  	servAddr.sin_family = AF_INET;
  	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  	servAddr.sin_port = htons(SERVER_PORT);
  	if(bind(sd, (struct sockaddr *) &servAddr, sizeof(servAddr))<0) 
	{
    		perror("cannot bind port ");
   		return ERROR;
  	}

  	listen(sd,5);
  
  	while(1) 
	{
    		printf("%s: waiting for data on port TCP %u\n",argv[0],SERVER_PORT);
    		cliLen = sizeof(cliAddr);
    		newSd = accept(sd, (struct sockaddr *) &cliAddr, &cliLen);
    		if(newSd<0) 
		{
      			perror("cannot accept connection ");
      			return ERROR;
    		}

    		memset(line, 0x0, MAX_MSG);
    
    		/* ����read_line�������������� */
    		while(read_line(newSd,line)!=ERROR) 
		{
      			printf("%s: received from %s:TCP%d : %s\n", argv[0], 
	     			inet_ntoa(cliAddr.sin_addr),
	     			ntohs(cliAddr.sin_port), line);
      			memset(line,0x0,MAX_MSG);
    		} 
  	}
}

/*  ����Ҫʱ���ݴ��׽��ֻ������ж�ȡ�������ǰ����ֽ�˳��
һ���ֽ�һ���ֽڵĶ�ȡ�����б����յ������ݶ�����ȡ����
�����С���������END_CHAR��Ϊ�����еĽ�������read_line
�������óɹ��򷵻����ȡ���ֽ�������Щ������ָ��line_to_return
ָ��			*/
int read_line(int newSd, char *line_to_return) 
{
  	static int rcv_ptr=0;
  	static char rcv_msg[MAX_MSG];
  	static int n;
  	int offset;

  	offset=0;
  	while(1) 
	{
    		if(rcv_ptr==0) 
		{
      			memset(rcv_msg, 0x0, MAX_MSG); 
      			n = recv(newSd, rcv_msg, MAX_MSG, 0); 
      			if (n<0) 
     			{
				perror(" cannot receive data ");
				return ERROR;
      			} 
			else if (n==0) 
			{
				printf(" connection closed by client\n");
				close(newSd);
				return ERROR;
        		}
    		}

    		/* ��ָ��line_to_returnָ��û����������� */
    		while(*(rcv_msg+rcv_ptr)!=END_LINE && rcv_ptr<n) 
		{
      			memcpy(line_to_return+offset,rcv_msg+rcv_ptr,1);
      			offset++;
      			rcv_ptr++;
    		}
    
    		/* end of line + end of buffer => return line */
    		if(rcv_ptr==n-1) 
		{ 
      			/* �����һ���ֽ�����ΪEND_LINE */
      			*(line_to_return+offset)=END_LINE;
      			rcv_ptr=0;
      			return ++offset;
    		} 
    
    		/* �����Ѿ����˶�ȡ���ݵ�ĩβ��
		���ǻ������л����������ݣ�
		��ʱ�����´��� */
    		if(rcv_ptr <n-1) 
		{
      			/* �������һ���ֽ�Ϊ END_LINE */
      			*(line_to_return+offset)=END_LINE;
      			rcv_ptr++;
      			return ++offset;
    		}

    		/* �������Ѿ����˻�������ĩβ�����ǻ�����̫С��װ������Ҫ
		���յ����ݣ���ʱ�ȴ��׽������µ����ݵ���  */
    		if(rcv_ptr == n) 
		{
      			rcv_ptr = 0;
    		} 
    
  	}
}
  
