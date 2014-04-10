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
	//��������в����Ƿ���˶˿ں�
	if(argc!=2){
		printf("��ʽ: %s �˿ں�\n", argv[0]);
		return 0;
	}
	//�Ǽ�SIGCHLD�źţ����������ʬ����
	signal(SIGCHLD, func);
	//�����׽��֣��������ļ�������
	int ss = socket(AF_INET/*IPv4*/, SOCK_STREAM/*TCP*/, 0);
	if(ss<0){
		puts("socket");
		return 1;
	}
	//Ϊ�׽��ְ��׽���Ϣ
	SI s;
	s.sin_family = AF_INET;
	s.sin_port = htons(atoi(argv[1]));
	s.sin_addr.s_addr = INADDR_ANY;//0����ʾ����������IP��ַ
	if(bind(ss, (SA*)&s, sizeof(s))<0){
		puts("bind");
		return 2;
	}
	//ת�������·����
	listen(ss, 10);
	//�ȴ�����������ͻ�����������
	socklen_t len;
	for(;;){
		//������������
		len = sizeof(s);
		int sc = accept(ss, (SA*)&s, &len);
		if(sc<0) continue;
		//��¼�Է�IP��ַ����ʾ
		char ip[100];
		strcpy(ip, inet_ntoa(s.sin_addr));
		printf("%s����һ��\n", ip);
		//��ʼ������
		if(fork()!=0){//�ɽ��̹ر����׽��ּ���ѭ��
			close(sc);
			continue;
		}
		//�½��̹رվ��׽���֮����ͻ���ͨ��Ȼ�����
		close(ss);
		//׼����ӭ��
		char msg[1000]="Ȩ�绶ӭ��������IP��";
		strcat(msg,ip);
		strcat(msg,"\n");
		for(;;){
			//�������ݵ��ͻ���
			write(sc, msg, strlen(msg));
			//��ȡ���Կͻ��˵�����
			int n = read(sc, msg, sizeof(msg)-1);
			if(n<=0) break;
			//��ʾ���Կͻ��˵�����
			msg[n] = '\0';
			printf("%s:%s", ip, msg);
			//����q��ͷ�ͶϿ�
			if(msg[0]=='q') break;
		}
		close(sc);
		printf("%s�˳���\n", ip);
		return 0;
	}
	return 0;
}

