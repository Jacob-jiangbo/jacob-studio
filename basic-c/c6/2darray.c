#include <stdio.h>

int main()
{
	char str[100] = "hello";
	char s[5][100]//5��Ԫ��:s[0],s[1],s[2],s[3],s[4],ÿ��Ԫ�ض���char[100]
			={"ţ��","������","����","���","С��Ů"};
	int score[20]={80,60,90,75};
	int age[5][9]={//5��ing[9]
		{25,22,23,20,28,19,21,26,22},//age[0]
		{21,23,18,18},//age[1]
		{20},//age[2]
		{20},//age[3]
		{0,22}//age[4]
	};//age[0][0]~age[4][8], age[0][0]~age[0][44]
	int i, j;
	for(i=0; i<5; i++)
		printf("%s\n", s[i]);
	for(i=0; i<5; i++){
		for(j=0; j<9; j++){
			printf("%d ", age[i][j]);
		}
		printf("\n");
	}
	return 0;
}
