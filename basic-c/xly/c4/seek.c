#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
/*
lseek(�ļ���������ƫ�������ο���)
*/
int main()
{
	int fd = open("asc", O_RDWR);
	if(fd<0){
		printf("�޷����ļ�asc\n");
		return 1;
	}
	lseek(fd, 4, SEEK_SET);
	char c1, c2;
	read(fd, &c1, 1);
	lseek(fd, 9, SEEK_CUR);
	read(fd, &c2, 1);
	lseek(fd, -11, SEEK_CUR);
	write(fd, &c2, 1);
	lseek(fd, 9, SEEK_CUR);
	write(fd, &c1, 1);
	lseek(fd, -1, SEEK_END);
	write(fd, "*\n", 2);
	close(fd);
}

