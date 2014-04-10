#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

typedef struct sockaddr_in SI;//IPV4结构体类型 重命名
typedef struct sockaddr SA;//标准结构体类型 重命名
int main(int argc, char* argv[])
{
	//检查命令行格式是否正确
	if(argc!=3){
		printf("格式：%s 服务器IP 服务端口号\n", argv[0]);
		return 0;
	}
	//创建套接字
	int sc = socket(PF_INET, SOCK_STREAM, 0);//套接字定义格式
	if(sc<0){
		puts("socket");
		return 1;
	}
	//连接服务器套接信息
	SI s;  
	s.sin_family = PF_INET;
	s.sin_port = htons(atoi(argv[2]));//?将一个数字字符转换为数字
	s.sin_addr.s_addr = inet_addr(argv[1]);//??
	if(connect(sc, (SA*)&s, sizeof(s))<0){//??
		puts("connect");
		return 2;
	}
	//反复跟服务器通信
	char msg[1000];
	for(;;){
		int n = read(sc, msg, sizeof(msg)-1);
		if(n<=0) break;
		msg[n] = '\0';
		printf("来自服务器:%s", msg);
		printf("输入:");
		fgets(msg, sizeof(msg), stdin);
		write(sc, msg, strlen(msg));
		if(msg[0]=='q') break;
	}
	//断开
	close(sc);
	return 0;
}

