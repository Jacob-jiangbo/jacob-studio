#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int copy(const char* oldfile, const char* newfile)
{
	int f1 = open(oldfile, O_RDONLY);
	if(f1<0) return 1;//表示失败之一
	int f2 = open(newfile, O_WRONLY|O_TRUNC|O_CREAT, 0644);
	if(f2<0) return 2;//表示失败之二
	int len;
	char buf[100];
	while((len=read(f1,buf,100))>0)
	{
		write(f2,buf,len);
	}
	close(f1);
	close(f2);
	return 0;//表示成功
}

int main(int argc, char* argv[])
{
	if(argc!=3)
	{
		printf("格式: %s 旧文件名 新文件名\n", argv[0]);
		return 0;
	}
	if(copy(argv[1], argv[2])==0)
		printf("复制文件成功\n");
	else
		printf("复制文件失败\n");
	return 0;
}

