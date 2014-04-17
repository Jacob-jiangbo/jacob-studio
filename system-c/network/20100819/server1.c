#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
/* ������Ҫ�����ı��ض˿� */
#define MYPORT 4000
/* �ܹ�ͬʱ���ܶ���û��accept ������ */
#define BACKLOG 10
main()
{
	/* ��sock_fd �Ͻ��м�����new_fd �����µ����� */
	int sockfd, new_fd ;
	/* �Լ��ĵ�ַ��Ϣ */
	struct sockaddr_in my_addr;
	/* �����ߵĵ�ַ��Ϣ*/
	struct sockaddr_in their_addr;
	int sin_size;
	/* �����������һֱǿ���Ĵ����飮�������socket() �����򷵻� */ 
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		/* ���������ʾ���˳� */
		perror("socket");
		exit(1);
	}
	/* �����ֽ�˳�� */
	my_addr.sin_family = AF_INET;
	/* �����ֽ�˳�򣬶����� */
	my_addr.sin_port = htons(MYPORT);
	/* �����г��������IP �����s_addr */
	my_addr.sin_addr.s_addr = INADDR_ANY;
	/* ���˽ṹ������ռ����� */
	bzero(&(my_addr.sin_zero), 8);
	/* ����������һֱǿ���Ĵ����飡�� */ 
	if (bind(sockfd, (struct sockaddr *)&my_addr,
	sizeof(struct sockaddr)) == -1)
	{
		/* �������bind()ʧ�ܣ������������ʾ���˳� */
		perror("bind");
		exit(1);
	}
	/* ����������һֱǿ���Ĵ����飡�� */
	if (listen(sockfd, BACKLOG) == -1)
	{
		/* �������listen ʧ�ܣ������������ʾ���˳� */
		perror("listen");
		exit(1);
	}
	while(1)
	{
		/* ��������accept()ѭ�� */
		sin_size = sizeof(struct sockaddr_in);
		/* ����������һֱǿ���Ĵ����飡�� */
		if ((new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size)) == -1)
		{
			/* �������accept()���ִ��������������ʾ��������һ��ѭ�� */
			perror("accept");
			continue;
		}
		/* �����������������ӵ���Ϣ */
		printf("server: got connection from %s\n", inet_ntoa(their_addr.sin_addr));
		/* ���ｫ����һ���ӽ������͸ոս������׽��ֽ���ͨѶ */
		if (!fork())
		/* �������ӽ��� */
		/* �����������˵�Ĵ����飡 */
		if (send(new_fd, "Hello, world!\n", 14, 0) == -1)
		{
			/* ������������������ʾ��Ȼ��ر���������ӣ��˳� */
			perror("send");
			close(new_fd);
			exit(0);
		}
		/* �ر�new_fd ���������׽������� */
		close(new_fd);
	}
//}
	/* �ȴ����е��ӽ��̶��˳� */
	while(waitpid(-1,NULL,WNOHANG) > 0);
}

