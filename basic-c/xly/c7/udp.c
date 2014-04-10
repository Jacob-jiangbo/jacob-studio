#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if(argc!=2){
		printf("用法：%s 端口号\n", argv[0]);
		return 0;
	}
	int fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(fd<0){
		puts("socket");
		return 1;
	}
	struct sockaddr_in s;
	s.sin_family = AF_INET;
	s.sin_port = htons(atoi(argv[1]));
	s.sin_addr.s_addr = INADDR_ANY;
	if(bind(fd, (struct sockaddr*)&s, sizeof(s))<0){
		puts("bind");
		return 2;
	}
	char ip[100], msg[1000];
	socklen_t len;
	short port;
	char c;
	int n;
	for(;;){
		len = sizeof(s);
		printf("r/s/q:");
		scanf(" %c", &c);
		if(c=='r'){//收信息
			while( (n=recvfrom(fd, msg, sizeof(msg)-1, MSG_DONTWAIT,
						(struct sockaddr*)&s,&len))>0 ){
				msg[n] = '\0';
				printf("%s@%d:%s", 
					inet_ntoa(s.sin_addr), ntohs(s.sin_port), msg);
			}
		}
		else if(c=='s'){//发信息
			scanf("%s%hd %[^\n]", ip, &port, msg);
			strcat(msg, "\n");
			s.sin_family = AF_INET;
			s.sin_port = htons(port);
			s.sin_addr.s_addr = inet_addr(ip);
			sendto(fd, msg, strlen(msg), 0,
				(struct sockaddr*)&s, len);
		}
		else
			break;
	}
	close(fd);
	return 0;
}

