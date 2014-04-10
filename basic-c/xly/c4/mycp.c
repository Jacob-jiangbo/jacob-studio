#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int copy(const char* oldfile, const char* newfile)
{
	int f1 = open(oldfile, O_RDONLY);
	if(f1<0) return 1;//��ʾʧ��֮һ
	int f2 = open(newfile, O_WRONLY|O_TRUNC|O_CREAT, 0644);
	if(f2<0) return 2;//��ʾʧ��֮��
	int len;
	char buf[100];
	while((len=read(f1,buf,100))>0)
	{
		write(f2,buf,len);
	}
	close(f1);
	close(f2);
	return 0;//��ʾ�ɹ�
}

int main(int argc, char* argv[])
{
	if(argc!=3)
	{
		printf("��ʽ: %s ���ļ��� ���ļ���\n", argv[0]);
		return 0;
	}
	if(copy(argv[1], argv[2])==0)
		printf("�����ļ��ɹ�\n");
	else
		printf("�����ļ�ʧ��\n");
	return 0;
}

