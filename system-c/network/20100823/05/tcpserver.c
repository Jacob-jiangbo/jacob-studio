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

/* 定义函数 readline */
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
    
    		/* 调用read_line函数来接收数据 */
    		while(read_line(newSd,line)!=ERROR) 
		{
      			printf("%s: received from %s:TCP%d : %s\n", argv[0], 
	     			inet_ntoa(cliAddr.sin_addr),
	     			ntohs(cliAddr.sin_port), line);
      			memset(line,0x0,MAX_MSG);
    		} 
  	}
}

/*  当必要时数据从套接字缓冲区中读取，但不是按照字节顺序
一个字节一个字节的读取。所有被接收到的数据都被读取到缓
冲区中。可以设置END_CHAR作为数据行的结束符。read_line
函数调用成功则返回其读取的字节数，这些数据由指针line_to_return
指向。			*/
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

    		/* 把指针line_to_return指向该缓冲区的数据 */
    		while(*(rcv_msg+rcv_ptr)!=END_LINE && rcv_ptr<n) 
		{
      			memcpy(line_to_return+offset,rcv_msg+rcv_ptr,1);
      			offset++;
      			rcv_ptr++;
    		}
    
    		/* end of line + end of buffer => return line */
    		if(rcv_ptr==n-1) 
		{ 
      			/* 将最后一个字节设置为END_LINE */
      			*(line_to_return+offset)=END_LINE;
      			rcv_ptr=0;
      			return ++offset;
    		} 
    
    		/* 尽管已经到了读取数据的末尾，
		但是缓冲区中还有其他数据，
		这时做如下处理： */
    		if(rcv_ptr <n-1) 
		{
      			/* 设置最后一个字节为 END_LINE */
      			*(line_to_return+offset)=END_LINE;
      			rcv_ptr++;
      			return ++offset;
    		}

    		/* 或者是已经到了缓冲区的末尾，但是缓冲区太小，装不下需要
		接收的数据，这时等待套接字上新的数据到达  */
    		if(rcv_ptr == n) 
		{
      			rcv_ptr = 0;
    		} 
    
  	}
}
  
