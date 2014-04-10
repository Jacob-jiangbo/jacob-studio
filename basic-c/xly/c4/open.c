#include <fcntl.h>//File CoNTroL Headerfile
#include <stdio.h>//STandarD Input/Output Headerfile
#include <sys/types.h>//一些类型定义
#include <sys/stat.h>//一些符号常量定义
/*
open(文件路径,打开方式)
open(文件路径,打开方式,权限)
权限用八进制数表示，只有在新建文件时才有效。
返回的是文件描述符，代表打开的文件，-1表示打开不成功，非负表示成功。
打开方式：三选一（O_RDONLY只读,O_WRONLY只写,O_RDWR既读又写）
如果文件不存在，打开一定失败，除非打开方式跟O_CREAT组合，这时如果文件不存在就会新建一个，使用指定的权限。文件已经存在就忽略O_CREAT和权限。
打开后文件内容不会丢失，如果想清空文件原有内容，打开方式组合O_TRUNC。
打开后向文件中写数据总是从文件头部写，覆盖原来相应位置的数据，不影响后面的数据。如果想要不覆盖而是追加在末尾，打开方式要组合O_APPEND。
close(文件描述符)关闭文件，释放资源。
*/

int main()
{
	umask(0);
	int fd = open("file1", O_WRONLY|O_CREAT, 0666);
	if(fd==-1)
	{
		printf("打开文件file1失败\n");
		return 1;
	}
	else
	{
		printf("打开文件file1成功\n");
		close(fd);
	}
	return 0;
}

