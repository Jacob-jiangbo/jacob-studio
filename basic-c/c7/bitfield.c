#include <stdio.h>
typedef struct field{//位段
	unsigned char a:3;//不允许超过8位
	unsigned char b:2;
	unsigned char c:1;
	unsigned char d:1;
//	unsigned e:24;
}field;//按char的字节数（1字节）补齐
//unsigned == unsigned int
typedef struct date{
	unsigned y:16;//可以超过8位
	unsigned m:4;
	unsigned d:5;
}date;
typedef struct{
	char c;
	int b;
	short d;
	double e;
	char f;
}a;
typedef struct{
//	unsigned x[8];
	unsigned b1:1;
	unsigned b2:1;
	unsigned b3:1;
	unsigned b4:1;
	unsigned b5:1;
	unsigned b6:1;
	unsigned b7:1;
	unsigned b8:1;
//	unsigned nouse:24;
}bits;//按unsigned int的字节数（4字节）补齐
typedef union{
	char c;
	bits b;
}CHAR;
int main()
{
	field f={5,2,0,1};
	printf("size:%d\n", sizeof(f));
	printf("%d,%d,%d,%d\n", f.a, f.b, f.c, f.d);
	date today={2010,7,21};
	printf("%u-%u-%u\n", today.y, today.m, today.d);
	CHAR ch = {'a'};
	printf("%u%u%u%u%u%u%u%u\n",ch.b.b1,ch.b.b2,ch.b.b3,
		   ch.b.b4,ch.b.b5,ch.b.b6,ch.b.b7,ch.b.b8);
	printf("size:%d\n",sizeof(a));
	a a,b,c,d,e,g,h,i,j,k;
	printf("address:%p\n",&a.e);
	printf("address:%p\n",&b.e);
	printf("address:%p\n",&c.e);
	printf("address:%p\n",&d.e);
	printf("address:%p\n",&e.e);
//	printf("address:%p\n",&f);
	return 0;
	
}

