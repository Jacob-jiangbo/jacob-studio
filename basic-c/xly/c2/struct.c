#include <stdio.h>
#include <string.h>
typedef struct Person{
	int id;
	char name[20];
	char gender;
	double score;
	short weight;
} XX;//定义结构体类型struct Person及其别名XX

struct Person zc={3,"张超",'M',99.9,123};//定义结构体变量zc
int main()
{
	struct Person xxy={7,"解小燕",'F',98.7,45};//定义结构体变量xxy
	struct Person nc=zc;
//	typedef struct Person XX;
	XX gc=zc;
	XX fr;
	gc.id = 8;
	strcpy(gc.name, "高超");
	strcpy(nc.name, "牛超");//字符串复制
	nc.score = 100;
	nc.id = 9;
	printf("%d号%s,%s性，体重%d,成绩%.2f\n", zc.id, zc.name,
		zc.gender=='M'?"男":"女", zc.weight, zc.score);
	printf("%d号%s,%s性，体重%d,成绩%.2f\n", xxy.id, xxy.name,
		xxy.gender=='M'?"男":"女", xxy.weight, xxy.score);
	printf("%d号%s,%s性，体重%d,成绩%.2f\n", nc.id, nc.name,
		nc.gender=='M'?"男":"女", nc.weight, nc.score);
	printf("%d号%s,%s性，体重%d,成绩%.2f\n", gc.id, gc.name,
		gc.gender=='M'?"男":"女", gc.weight, gc.score);
	printf("%d号%s,%s性，体重%d,成绩%.2f\n", fr.id, fr.name,
		fr.gender=='M'?"男":"女", fr.weight, fr.score);
	printf("请输入id、姓名、性别（M/F)、体重和成绩:\n");
	scanf("%d %s %c %hd %lf", &fr.id, &fr.name, &fr.gender, &fr.weight, &fr.score);
	printf("%d号%s,%s性，体重%d,成绩%.2f\n", fr.id, fr.name,
		fr.gender=='M'?"男":"女", fr.weight, fr.score);
	return 0;
}

