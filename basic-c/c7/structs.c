#include <stdio.h>
typedef struct{
	int year;
	int month;
	int day;
}date;
typedef struct{
	char name[20];
	char gender;
	date birth;
	double salary;
}person;
int main()
{
	person p1={"‹Ω»ÿ",'F',{1992,7,21},8000};
	printf("%s:%d\n", p1.name, p1.birth.year);
	person gsd[3]={
		{"—Ó«ø",'M',{1978,5,6},9000},
		{"–Ïﬁ±ﬁ±",'F',{1986,9,30},6000},
		p1
	};
	int i;
	for(i=0; i<3; i++)
		printf("%s:\t%d,%.2f\n",
			   gsd[i].name,gsd[i].birth.year,gsd[i].salary);
	return 0;
}
