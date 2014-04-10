#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
//定义学生结构
typedef struct student{
	char name[20];
	double score;
}Stu;
//清除输入末尾的换行符
void clear()
{
	char c;
	while(scanf("%c",&c)==1&&c!='\n'){}
}
//让用户选择一个功能
int choose()
{
	char c;
	for(;;){
		puts("1--增加学生");
		puts("2--输入成绩");
		puts("3--列出学生信息");
		puts("0--退出");
		printf("请选择:");
		scanf(" %c", &c);
		if(c>='0'&&c<='3') break;
	}
	clear();
	return c;
}
//添加一个学生
void addstudent(int fd, int* p)
{
	Stu s;
	printf("请输入姓名:");
	scanf("%s", s.name);
	s.score = -1;
	lseek(fd, 0, SEEK_END);
	write(fd, &s, sizeof(Stu));
	++*p;
	printf("新生的学号是:%d\n", *p);
}
//设置学生成绩
void setscore(int fd, int* p)
{
	int num=-1;
	double score=-1;
	printf("请输入学号和成绩:");
	scanf("%d%lf", &num, &score);
	clear();
	if(num<1||num>*p||score<0||score>100){
		printf("无效学号或者成绩!\n");
		return;
	}
	lseek(fd, (num-1)*sizeof(Stu), SEEK_SET);
	Stu s;
	read(fd, s.name, sizeof(s.name));
	printf("把%s的成绩设置成%g\n", s.name, score);
	write(fd, &score, sizeof(score));
}
//列出学生信息
void liststudent(int fd, int* p)
{
	int num=-1;
	Stu s;
	printf("请输入学号(0表示全部):");
	scanf("%d", &num);
	clear();
	if(num<0||num>*p){
		printf("无效学号\n");
		return;
	}
	int from, to;
	if(num==0) from=1,to=*p;
	else from=to=num;
	lseek(fd, (from-1)*sizeof(Stu), SEEK_SET);
	int i;
	for(i=from; i<=to; i++){
		read(fd, &s, sizeof(Stu));
		printf("%s\t%g\n", s.name, s.score);
	}
}
int main()
{
	//打开文件
	int fd = open("stu.dat", O_RDWR|O_CREAT, 0600);
	if(fd<0){
		printf("无法打开文件stu.dat\n");
		return 1;
	}
	int cnt = lseek(fd, 0, SEEK_END)/sizeof(Stu);
	printf("已有学生人数:%d\n", cnt);
	//反复让用户选择操作
	for(;;){
		int ch = choose();
		if(ch=='0') break;
		else if(ch=='1') addstudent(fd,&cnt);
		else if(ch=='2') setscore(fd,&cnt);
		else if(ch=='3') liststudent(fd,&cnt);
		else{/*不可能*/}
	}
	//退出时关闭文件，保证数据能保存到文件中
	close(fd);
	return 0;
}

