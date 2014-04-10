#include <stdio.h>
#include <unistd.h>//unix standard headerfile
#include <fcntl.h>
/*
read(文件描述符，放到内存什么地址，想从文件中读取多少字节）
返回成功读取的字节数，也就是从文件向内存传递的字节数，可能比想读的要少。
如果返回0表示文件已经读完，超越了文件末尾。
如果返回-1表示读取出错了。
*/
int main(int argc, char* argv[])
{
	if(argc==1){
		printf("格式:%s 文件名\n", argv[0]);
		return 0;
	}
	int fd = open(argv[1], O_RDONLY);
	if(fd==-1){
		printf("无法打开文件%s\n", argv[1]);
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

