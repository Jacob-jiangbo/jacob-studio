#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
//����ѧ���ṹ
typedef struct student{
	char name[20];
	double score;
}Stu;
//�������ĩβ�Ļ��з�
void clear()
{
	char c;
	while(scanf("%c",&c)==1&&c!='\n'){}
}
//���û�ѡ��һ������
int choose()
{
	char c;
	for(;;){
		puts("1--����ѧ��");
		puts("2--����ɼ�");
		puts("3--�г�ѧ����Ϣ");
		puts("0--�˳�");
		printf("��ѡ��:");
		scanf(" %c", &c);
		if(c>='0'&&c<='3') break;
	}
	clear();
	return c;
}
//���һ��ѧ��
void addstudent(int fd, int* p)
{
	Stu s;
	printf("����������:");
	scanf("%s", s.name);
	s.score = -1;
	lseek(fd, 0, SEEK_END);
	write(fd, &s, sizeof(Stu));
	++*p;
	printf("������ѧ����:%d\n", *p);
}
//����ѧ���ɼ�
void setscore(int fd, int* p)
{
	int num=-1;
	double score=-1;
	printf("������ѧ�źͳɼ�:");
	scanf("%d%lf", &num, &score);
	clear();
	if(num<1||num>*p||score<0||score>100){
		printf("��Чѧ�Ż��߳ɼ�!\n");
		return;
	}
	lseek(fd, (num-1)*sizeof(Stu), SEEK_SET);
	Stu s;
	read(fd, s.name, sizeof(s.name));
	printf("��%s�ĳɼ����ó�%g\n", s.name, score);
	write(fd, &score, sizeof(score));
}
//�г�ѧ����Ϣ
void liststudent(int fd, int* p)
{
	int num=-1;
	Stu s;
	printf("������ѧ��(0��ʾȫ��):");
	scanf("%d", &num);
	clear();
	if(num<0||num>*p){
		printf("��Чѧ��\n");
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
	//���ļ�
	int fd = open("stu.dat", O_RDWR|O_CREAT, 0600);
	if(fd<0){
		printf("�޷����ļ�stu.dat\n");
		return 1;
	}
	int cnt = lseek(fd, 0, SEEK_END)/sizeof(Stu);
	printf("����ѧ������:%d\n", cnt);
	//�������û�ѡ�����
	for(;;){
		int ch = choose();
		if(ch=='0') break;
		else if(ch=='1') addstudent(fd,&cnt);
		else if(ch=='2') setscore(fd,&cnt);
		else if(ch=='3') liststudent(fd,&cnt);
		else{/*������*/}
	}
	//�˳�ʱ�ر��ļ�����֤�����ܱ��浽�ļ���
	close(fd);
	return 0;
}

