/*  vcserver.c  server  */

#include <stdio.h>
#include "stdlib.h"
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>   
#include <netdb.h> 
main (int argc, char *argv[])
{
   	int rc, new_sd, sock, adrlen, cnt;       
   	struct sockaddr_in myname;  
   	struct sockaddr_in *nptr;   /* ptr ��ȡ�˿ں� */
   	struct sockaddr    addr;  
   	char buf[80];   
   	struct hostent *hp;

   	printf("\nThis is the network server with pid %d\n", getpid() );

   	if (( sock = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) 
	{
      		printf("network server socket failure %d\n", errno);
      		perror("network server");
      		exit(1);
   	}

   	myname.sin_family = AF_INET; 
   	myname.sin_port = 0;  
   	myname.sin_addr.s_addr = INADDR_ANY;  

   	if (bind(sock, &myname, sizeof(myname) ) < 0 ) 
	{
      		close(sock);  /* defensive programming  */
      		printf("network server bind failure %d\n", errno);
      		perror("network server");
      		exit(2);
   	}

   	adrlen = sizeof(addr); /* ��ַ����Ϊ����ֵ */
   	if ( ( rc = getsockname( sock, &addr, &adrlen ) ) < 0 )
   	{
      		printf("setwork server getsockname failure %d\n", errno);
      		perror("network server");
      		close (sock);
      		exit(3);
   	}

   	nptr = (struct sockaddr_in *) &addr;  /* port # */
   	printf("\n\tnetwork server: server has port number: %d\n", ntohs ( nptr -> sin_port ) );

   	/*  ����listen()���� */
   	if ( listen ( sock, 5 ) < 0 ) 
	{
      		printf("network server bind failure %d\n", errno);
      		perror("network server");
      		close (sock);
      		exit(4);
   	}

   	while (1) 
	{
      		if ( ( new_sd = accept ( sock, 0, 0 ) ) < 0 ) 
		{
         		printf("network server accept failure %d\n", errno);
         		perror("network server");
         		close (sock);
         		exit(5);
      		}
      		/* ͨ��fork()���������ӽ���������ͻ��˷�������*/
      		if ( ( fork() ) == 0 ) 
		{
         		int pid;
         		pid = getpid();   /* ��ȡ�ӽ��̵�PID */
         		close (sock); /* �ӽ����в�����Ҫ�����̵Ĳ��� */

         		/* ���ҳ��ͻ������ڡ�ע��ͨ���׽��ֵ�ַ�ṹaddr���÷�����ȡ�ͻ�����Ϣ      */ 
         		if ((rc = getpeername( new_sd, &addr, &adrlen )) < 0) 
			{
	            		printf("network server %d getpeername failure %d\n",
	                 		pid, errno);
	            		perror("network server");
			       close(new_sd);
            			exit(6);
         		}
         		
         		printf("\n\tnetwork server %d:", pid);
         		printf(" client socket from host %s\n", inet_ntoa ( nptr -> sin_addr ) );
         		printf("\t has port number %d\n",  nptr -> sin_port);
         		/*	�����ҵ���������ͻ�����ص���Ϣ�����ҿ���ͨ����/etc/hosts
			�в�����ȷ���ͻ��˵�����   */
         		if (( hp = gethostbyaddr (&nptr -> sin_addr, 4, AF_INET)) != NULL ) 
         		{
            			printf ("\tfrom hostname: %s\n\twith aliases: ", hp -> h_name );
            			while ( *hp -> h_aliases )
               			printf ("\n\t\t\t%s", *hp -> h_aliases++ );
            			printf("\n\n");
         		}
         		else 
			{
            			printf("network server %d ", pid);
            			printf("gethostbyaddr failure %d\n", h_errno);
            			perror("network server");
         		}

         		do {
            			memset  (buf,0,sizeof(buf));
             			if (( cnt = read (new_sd, buf, sizeof(buf))) < 0 ) 
            			{
               			printf("network server %d ", pid);
               			printf("socket read failure &d\n", errno);
               			perror("network server");
               			close(new_sd);
               			exit(7);
            			}
            			else if (cnt == 0) 
				{
               			printf("network server received message");
               			printf(" of length %d\n", cnt);
               			printf("network server closing");
               			printf(" client connection...\n");
               			close (new_sd);
               			continue;
            			}
            			else 
				{ 
               			printf("network server %d received message",pid);
               			printf(" of length %d\n", cnt);
               			printf("network server %d  received", pid);
               			printf(" the message %s\n", buf);
               			memset  (buf,0,sizeof(buf));  /* ��ջ����� */
               			strcpy(buf, "Message from server to client");
               			write (new_sd, buf, sizeof(buf));
            			}  /* end of message-print else */
         		}while (cnt != 0);  
         		exit(0); 

      		} 

      		else   
         	close (new_sd); 

   	}  
}  
