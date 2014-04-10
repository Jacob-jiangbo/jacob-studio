#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct student{
    char name[10];
    int num;
}stu;

int choose ()
{	puts("1--增加姓名");
	puts("0--退出");
	printf("请输入：\n");
	char c;
	scanf("%c",&c);
	if(c>='0'&&c<='2') return c;
}

void addstudentname(int fd,int* p)
{	printf("现在共有学生 %d",*p);
	stu s;
	scanf("%s",s.name);
	s.num = -1;
	lseek(fd,0,SEEK_END);
	write(fd,&s,sizeof(stu));
	++*p;
	printf("新生的学号%d\n",*p);
}

void liststudent(int fd,int* p)
{	int num=-1;
	stu s;
	printf("请输入学号：（0表示全部）");
	scanf("%d",&num);
	if(num<0||num>*p){
		printf("无效学号！\n");
	int from,to;
	if(num==0) {from=1;to=*p;}	
	else from=to=num;
	lseek(fd,(from-1)*sizeof(stu),SEEK_SET);
	int i;
	for(i=from;i<=to;i++){
		read(fd,&s,sizeof(stu));
		printf("%s\t%g\n",s.name,s.num);
	}
}

int main()
{	int fd = open("stu.dat",O_RDONLY|O_CREAT,0600);
	if(fd<0){
		printf("无法打开文件");
		return 1;
	}
	int cnt = lseek(fd,0,SEEK_END)/sizeof(stu);
	
	for(;;)
	{	char c;
		stu s;
		c=choose();
		if(c=='0')  break;
		else if(c=='1')  addstudentname(fd,&cnt);
		else if(c=='2')  liststudent(fd,&cnt);
		else {}
	}	
	close(fd);
	return 0;
      
}
