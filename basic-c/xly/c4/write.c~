#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
/*
write(文件描述符，要把内存那个地址的数据写到文件中，要写多少个字节数据）
返回成功写入文件的字节数，失败返回-1。
*/
typedef struct {
	char name[20];
	short int age;
	double salary;
}Person;
int main()
{
	char a='*';
	char b[6]="hello";
	int c=1234567890;
	float f=1234.5;
	double d=6789.0123;
	Person e={"马春花", 18, 12345.67};
	int fd = open("file2", O_WRONLY|O_CREAT|O_TRUNC, 0644);
	if(fd<0){
		printf("无法打开文件file2\n");
		return 1;
	}
	write(fd, &a, sizeof(a));
	write(fd, &b, sizeof(b));
	write(fd, &c, sizeof(c));
	write(fd, &d, sizeof(d));
	write(fd, &e, sizeof(e));
	write(fd, &f, sizeof(f));
	close(fd);
	return 0;
}

