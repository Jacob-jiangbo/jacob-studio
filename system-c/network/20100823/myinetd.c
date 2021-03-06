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

	/* server端启动之后，它首先fork子进程，让子进程来做所有的工作，所以它并不是必须在后台运行。
		在此之后它就建立好监听的socket，并为每一个连接都fork一个子进程来处理不同的连接。*/
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
  	/* 现在，所有的server端的初始化工作都已完成。现在我们就可以fork出守护进程并且将它返回给用户。
	   我们需要setpgrp，这样守护进程就将不再属于任何的客户终端了。这些都应该在fork 之前完成，
	   这样子进程将不会成为一个进程组的头进程。否则，如果子进程打开了一个终端，它将会把此终端作为它的控制终端。
	   通常都是由父进程作setpgrp的。*/
       setpgrp(); 
  	printf ("getpid = %d, getpgid = %d\n", getpid(), getpgid(getpid()));
       switch (fork()) 
	{ 
        	case -1:               
                	perror(argv[0]); 
                	fprintf(stderr, "%s: unable to fork daemon\n", argv[0]); 
                	exit(1); 
  		case 0:                 
			/* 子进程系即守护进程就是在这里形成的。它关闭调标准输入和标准错误输出，标准输出被重定向到日志文件中
		   	或者是 /dev/null中去。从现在开始，守护进程将不会报告任何错误信息。这个守护进程将会永久的循环下去
  		   	等待连接然后fork出一个子进程来处理该连接。*/
                	fclose(stdin); 
                	fclose(stderr); 
 
			/* 将SIGCLD信号的处理方式设置为忽略目的是防止每个子进程在终止后变成托孤进程。
		   	这也就意味着 守护进程 并不需要一定要使用 wait 调用来清理它们。*/
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
					/* 守护进程到此就已经实现了。守护进程必须记着在它fork出子进程后关闭父进程中的新连接，
				   	这样可以防止守护进程出现文件描述符溢出的错误。这同时也意味着当server端中断的连接后，
				   	允许这个socket被销毁。*/
					close(s); 
                        	} 
                	} 
        	default:                /* 父进程 */ 
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

	close(ls);//好习惯 
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

	/* 进入一个循环，接收客户端请求。在客户端发送完最后一个请求之后将发送一此终止，
	这将产生一个文件结束标志。当客户端所有的请求都发送完之后并且北接收到之后，下一个recv调用将返回一个空字节，
	标志文件结束。这样，服务器端就会知道将不会再有请求了，循环也将终止。*/
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
