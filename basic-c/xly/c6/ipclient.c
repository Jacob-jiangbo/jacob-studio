#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

typedef struct sockaddr_in SI;//IPV4�ṹ������ ������
typedef struct sockaddr SA;//��׼�ṹ������ ������
int main(int argc, char* argv[])
{
	//��������и�ʽ�Ƿ���ȷ
	if(argc!=3){
		printf("��ʽ��%s ������IP ����˿ں�\n", argv[0]);
		return 0;
	}
	//�����׽���
	int sc = socket(PF_INET, SOCK_STREAM, 0);//�׽��ֶ����ʽ
	if(sc<0){
		puts("socket");
		return 1;
	}
	//���ӷ������׽���Ϣ
	SI s;  
	s.sin_family = PF_INET;
	s.sin_port = htons(atoi(argv[2]));//?��һ�������ַ�ת��Ϊ����
	s.sin_addr.s_addr = inet_addr(argv[1]);//??
	if(connect(sc, (SA*)&s, sizeof(s))<0){//??
		puts("connect");
		return 2;
	}
	//������������ͨ��
	char msg[1000];
	for(;;){
		int n = read(sc, msg, sizeof(msg)-1);
		if(n<=0) break;
		msg[n] = '\0';
		printf("���Է�����:%s", msg);
		printf("����:");
		fgets(msg, sizeof(msg), stdin);
		write(sc, msg, strlen(msg));
		if(msg[0]=='q') break;
	}
	//�Ͽ�
	close(sc);
	return 0;
}

