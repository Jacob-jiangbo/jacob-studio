#include <stdio.h>
#include <unistd.h>//unix standard headerfile
#include <fcntl.h>
/*
read(�ļ����������ŵ��ڴ�ʲô��ַ������ļ��ж�ȡ�����ֽڣ�
���سɹ���ȡ���ֽ�����Ҳ���Ǵ��ļ����ڴ洫�ݵ��ֽ��������ܱ������Ҫ�١�
�������0��ʾ�ļ��Ѿ����꣬��Խ���ļ�ĩβ��
�������-1��ʾ��ȡ�����ˡ�
*/
int main(int argc, char* argv[])
{
	if(argc==1){
		printf("��ʽ:%s �ļ���\n", argv[0]);
		return 0;
	}
	int fd = open(argv[1], O_RDONLY);
	if(fd==-1){
		printf("�޷����ļ�%s\n", argv[1]);
		return 1;
	}
	char buf[101];
	int len;
	while( (len=read(fd,buf,100))!=0 ){
		if(len<0) break;
		buf[len] = 0;//'\0';
		printf("%s", buf);
	}
	close(fd);
	return 0;
}

