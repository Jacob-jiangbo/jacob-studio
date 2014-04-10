#include <stdio.h>

typedef union ip{
	unsigned int n;
	unsigned char field[4];
	double d;
	short s;
	char c;
}ip;
union Val{
	char c;
	short s;
	int n;
	long g;
	float f;
	double d;
};
struct Var{
	char type;
	union Val value;
};
int main()
{
	struct Var a;a.type='c';
	ip myip;
	printf("%p, %p, %p, %p\n", &myip, 
		   &myip.n, myip.field, &myip.d);
	printf("size:%d\n", sizeof(myip));
	myip.n = 0x12345678;
	printf("%x\n", myip.field[0]);
	ip server={0x88665533};
	printf("%x, %x\n", server.n, server.field[0]);
	ip client={field:{0x11,0x22,0x33,0x44}};
	printf("%x, %x\n", client.n, client.field[0]);
	return 0;
}
