#include <fcntl.h>//File CoNTroL Headerfile
#include <stdio.h>//STandarD Input/Output Headerfile
#include <sys/types.h>//һЩ���Ͷ���
#include <sys/stat.h>//һЩ���ų�������
/*
open(�ļ�·��,�򿪷�ʽ)
open(�ļ�·��,�򿪷�ʽ,Ȩ��)
Ȩ���ð˽�������ʾ��ֻ�����½��ļ�ʱ����Ч��
���ص����ļ�������������򿪵��ļ���-1��ʾ�򿪲��ɹ����Ǹ���ʾ�ɹ���
�򿪷�ʽ����ѡһ��O_RDONLYֻ��,O_WRONLYֻд,O_RDWR�ȶ���д��
����ļ������ڣ���һ��ʧ�ܣ����Ǵ򿪷�ʽ��O_CREAT��ϣ���ʱ����ļ������ھͻ��½�һ����ʹ��ָ����Ȩ�ޡ��ļ��Ѿ����ھͺ���O_CREAT��Ȩ�ޡ�
�򿪺��ļ����ݲ��ᶪʧ�����������ļ�ԭ�����ݣ��򿪷�ʽ���O_TRUNC��
�򿪺����ļ���д�������Ǵ��ļ�ͷ��д������ԭ����Ӧλ�õ����ݣ���Ӱ���������ݡ������Ҫ�����Ƕ���׷����ĩβ���򿪷�ʽҪ���O_APPEND��
close(�ļ�������)�ر��ļ����ͷ���Դ��
*/

int main()
{
	umask(0);
	int fd = open("file1", O_WRONLY|O_CREAT, 0666);
	if(fd==-1)
	{
		printf("���ļ�file1ʧ��\n");
		return 1;
	}
	else
	{
		printf("���ļ�file1�ɹ�\n");
		close(fd);
	}
	return 0;
}

