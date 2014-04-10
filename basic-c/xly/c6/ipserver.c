#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

void func(int signo)
{
	while(waitpid(-1,NULL,WNOHANG)>0){}
}
typedef struct sockaddr_in SI;
typedef struct sockaddr SA;
int main(int argc, char* argv[])
{
	//检查命令行参数是否带了端口号
	if(argc!=2){
		printf("格式: %s 端口号\n", argv[0]);
		return 0;
	}
	//登记SIGCHLD信号，以免产生僵尸进程
	signal(SIGCHLD, func);
	//创建套接字，类似于文件描述符
	int ss = socket(AF_INET/*IPv4*/, SOCK_STREAM/*TCP*/, 0);
	if(ss<0){
		puts("socket");
		return 1;
	}
	//为套接字绑定套接信息
	SI s;
	s.sin_family = AF_INET;
	s.sin_port = htons(atoi(argv[1]));
	s.sin_addr.s_addr = INADDR_ANY;//0，表示本机的所有IP地址
	if(bind(ss, (SA*)&s, sizeof(s))<0){
		puts("bind");
		return 2;
	}
	//转成允许多路接入
	listen(ss, 10);
	//等待并处理网络客户端连接请求
	socklen_t len;
	for(;;){
		//接受连接请求
		len = sizeof(s);
		int sc = accept(ss, (SA*)&s, &len);
		if(sc<0) continue;
		//记录对方IP地址并显示
		char ip[100];
		strcpy(ip, inet_ntoa(s.sin_addr));
		printf("%s到此一游\n", ip);
		//开始多任务
		if(fork()!=0){//旧进程关闭新套接字继续循环
			close(sc);
			continue;
		}
		//新进程关闭旧套接字之后跟客户端通信然后结束
		close(ss);
		//准备欢迎词
		char msg[1000]="权哥欢迎您，您的IP是";
		strcat(msg,ip);
		strcat(msg,"\n");
		for(;;){
			//发送数据到客户端
			write(sc, msg, strlen(msg));
			//读取来自客户端的数据
			int n = read(sc, msg, sizeof(msg)-1);
			if(n<=0) break;
			//显示来自客户端的数据
			msg[n] = '\0';
			printf("%s:%s", ip, msg);
			//遇到q开头就断开
			if(msg[0]=='q') break;
		}
		close(sc);
		printf("%s退出了\n", ip);
		return 0;
	}
	return 0;
}

