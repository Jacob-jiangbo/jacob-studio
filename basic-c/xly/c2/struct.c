#include <stdio.h>
#include <string.h>
typedef struct Person{
	int id;
	char name[20];
	char gender;
	double score;
	short weight;
} XX;//����ṹ������struct Person�������XX

struct Person zc={3,"�ų�",'M',99.9,123};//����ṹ�����zc
int main()
{
	struct Person xxy={7,"��С��",'F',98.7,45};//����ṹ�����xxy
	struct Person nc=zc;
//	typedef struct Person XX;
	XX gc=zc;
	XX fr;
	gc.id = 8;
	strcpy(gc.name, "�߳�");
	strcpy(nc.name, "ţ��");//�ַ�������
	nc.score = 100;
	nc.id = 9;
	printf("%d��%s,%s�ԣ�����%d,�ɼ�%.2f\n", zc.id, zc.name,
		zc.gender=='M'?"��":"Ů", zc.weight, zc.score);
	printf("%d��%s,%s�ԣ�����%d,�ɼ�%.2f\n", xxy.id, xxy.name,
		xxy.gender=='M'?"��":"Ů", xxy.weight, xxy.score);
	printf("%d��%s,%s�ԣ�����%d,�ɼ�%.2f\n", nc.id, nc.name,
		nc.gender=='M'?"��":"Ů", nc.weight, nc.score);
	printf("%d��%s,%s�ԣ�����%d,�ɼ�%.2f\n", gc.id, gc.name,
		gc.gender=='M'?"��":"Ů", gc.weight, gc.score);
	printf("%d��%s,%s�ԣ�����%d,�ɼ�%.2f\n", fr.id, fr.name,
		fr.gender=='M'?"��":"Ů", fr.weight, fr.score);
	printf("������id���������Ա�M/F)�����غͳɼ�:\n");
	scanf("%d %s %c %hd %lf", &fr.id, &fr.name, &fr.gender, &fr.weight, &fr.score);
	printf("%d��%s,%s�ԣ�����%d,�ɼ�%.2f\n", fr.id, fr.name,
		fr.gender=='M'?"��":"Ů", fr.weight, fr.score);
	return 0;
}

