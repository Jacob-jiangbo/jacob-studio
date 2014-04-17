#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <signal.h> 
#include <stdio.h> 
#include "stdlib.h"
#include <netdb.h> 
#include <unistd.h>
  
int s;                       
int ls;                      
  
struct hostent *hp;          
struct servent *sp;           
  
long timevar;                

struct sockaddr_in myaddr_in;   
struct sockaddr_in peeraddr_in;  

	/* server������֮��������fork�ӽ��̣����ӽ����������еĹ����������������Ǳ����ں�̨���С�
		�ڴ�֮�����ͽ����ü�����socket����Ϊÿһ�����Ӷ�forkһ���ӽ�����������ͬ�����ӡ�*/
int main(int argc, char *argv[]) 
{ 
	int addrlen; 
  	
	printf("getpid = %d, getpgid = %d\n", getpid(), getpgid(getpid()));
		
       memset ((char *)&myaddr_in, 0, sizeof(struct sockaddr_in)); 
       memset ((char *)&peeraddr_in, 0, sizeof(struct sockaddr_in)); 
  
       myaddr_in.sin_family = AF_INET; 
       myaddr_in.sin_addr.s_addr = INADDR_ANY; 
       /* sp = getservbyname ("myinetd", "tcp"); 
        if (sp == NULL) { 
                fprintf(stderr, "%s: example not found in /etc/services\n", 
                                argv[0]); 
                exit(1); 
        } 
        myaddr_in.sin_port = sp->s_port; 
	*/
  	myaddr_in.sin_port = htons(7000);
       ls = socket (AF_INET, SOCK_STREAM, 0); 
       if (ls == -1) 
	{ 
                perror(argv[0]); 
                fprintf(stderr, "%s: unable to create socket\n", argv[0]); 
                exit(1); 
        }  
       if (bind(ls, &myaddr_in, sizeof(struct sockaddr_in)) == -1) 
	{ 
                perror(argv[0]); 
                fprintf(stderr, "%s: unable to bind address\n", argv[0]); 
                exit(1); 
        } 
            
	printf("getpid = %d, getpgid = %d\n", getpid(), getpgid(getpid()));
 
       if (listen(ls, 5) == -1) 
	{ 
                perror(argv[0]); 
                fprintf(stderr, "%s: unable to listen on socket\n", argv[0]); 
                exit(1); 
        } 
  	/* ���ڣ����е�server�˵ĳ�ʼ������������ɡ��������ǾͿ���fork���ػ����̲��ҽ������ظ��û���
	   ������Ҫsetpgrp�������ػ����̾ͽ����������κεĿͻ��ն��ˡ���Щ��Ӧ����fork ֮ǰ��ɣ�
	   �����ӽ��̽������Ϊһ���������ͷ���̡���������ӽ��̴���һ���նˣ�������Ѵ��ն���Ϊ���Ŀ����նˡ�
	   ͨ�������ɸ�������setpgrp�ġ�*/
       setpgrp(); 
  	printf ("getpid = %d, getpgid = %d\n", getpid(), getpgid(getpid()));
       switch (fork()) 
	{ 
        	case -1:               
                	perror(argv[0]); 
                	fprintf(stderr, "%s: unable to fork daemon\n", argv[0]); 
                	exit(1); 
  		case 0:                 
			/* �ӽ���ϵ���ػ����̾����������γɵġ����رյ���׼����ͱ�׼�����������׼������ض�����־�ļ���
		   	������ /dev/null��ȥ�������ڿ�ʼ���ػ����̽����ᱨ���κδ�����Ϣ������ػ����̽������õ�ѭ����ȥ
  		   	�ȴ�����Ȼ��fork��һ���ӽ��������������ӡ�*/
                	fclose(stdin); 
                	fclose(stderr); 
 
			/* ��SIGCLD�źŵĴ�����ʽ����Ϊ����Ŀ���Ƿ�ֹÿ���ӽ�������ֹ�����й½��̡�
		   	��Ҳ����ζ�� �ػ����� ������Ҫһ��Ҫʹ�� wait �������������ǡ�*/
                	signal(SIGCLD, SIG_IGN); 
                	for(;;) 
			{ 
                	        addrlen = sizeof(struct sockaddr_in); 
                	        s = accept(ls, &peeraddr_in, &addrlen); 
                	        if ( s == -1) exit(1); 
                	        switch (fork()) 
				{ 
	                	       case -1:         
	                	                exit(1); 
	                	       case 0:         
	                	                server(); 
	                	                exit(0); 
					default:      
					/* �ػ����̵��˾��Ѿ�ʵ���ˡ��ػ����̱����������fork���ӽ��̺�رո������е������ӣ�
				   	�������Է�ֹ�ػ����̳����ļ�����������Ĵ�����ͬʱҲ��ζ�ŵ�server���жϵ����Ӻ�
				   	�������socket�����١�*/
					close(s); 
                        	} 
                	} 
        	default:                /* ������ */ 
			exit(0); 
        } 
} 
  
server( ) 
{ 
       int reqcnt = 0;        
       char buf[10];          
       char *inet_ntoa(); 
       char *hostname;      
       int len, len1; 

	close(ls);//��ϰ�� 
  	hp = gethostbyaddr ((char *) &peeraddr_in.sin_addr, sizeof (struct in_addr), 
                                peeraddr_in.sin_family); 
  	if (hp == NULL) 
	{ 
              hostname = inet_ntoa(peeraddr_in.sin_addr); 
        } 
	else 
	{ 
        	hostname = hp->h_name;  
        }  
       time (&timevar); 
       printf("Startup from %s port %u at %s", 
               hostname, ntohs(peeraddr_in.sin_port), ctime(&timevar)); 

	/* ����һ��ѭ�������տͻ��������ڿͻ��˷��������һ������֮�󽫷���һ����ֹ��
	�⽫����һ���ļ�������־�����ͻ������е����󶼷�����֮���ұ����յ�֮����һ��recv���ý�����һ�����ֽڣ�
	��־�ļ��������������������˾ͻ�֪�����������������ˣ�ѭ��Ҳ����ֹ��*/
       while (len = recv(s, buf, 10, 0)) 
	{ 
		if (len == -1) exit(1); 
		while (len < 10) 
		{ 
                        len1 = recv(s, &buf[len], 10-len, 0); 
                        if (len1 == -1) 
				exit(1); 
                        len += len1; 
                } 
		reqcnt++; 
		sleep(1); 
              if (send(s, buf, 10, 0) != 10) exit(1); 
        } 
}