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
	char a='\0';
	char b[6]="";
	int c=0;
	float f=0.0;
	double d=0.0;
	Person e={"权哥", 2, 1.7};
	int fd = open("file2", O_RDONLY);
	if(fd<0){
		printf("无法打开文件file2\n");
		return 1;
	}
	read(fd, &a, sizeof(a));
	read(fd, &b, sizeof(b));
	read(fd, &c, sizeof(c));
	read(fd, &d, sizeof(d));
	read(fd, &e, sizeof(e));
	read(fd, &f, sizeof(f));
	close(fd);
	printf("a=%c\n", a);
	printf("b=%s\n", b);
	printf("c=%d\n", c);
	printf("d=%lf\n", d);
	printf("e=[%s,%d,%g]\n", e.name,e.age,e.salary);
	printf("f=%g\n", f);
	return 0;
}

