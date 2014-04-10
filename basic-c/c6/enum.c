#include <stdio.h>
typedef enum Bool { true=1, false=0 } bool;
enum Gender { Female, Male };
enum Class { SD, TS, CSD=8, GSD, DB };
//#define GE enum Gender
typedef enum Gender ge;//给enum Gender类型起个别名ge
typedef char A[100];//给char[100]类型起个别名A
//typedef char[100] A;不允许这样的格式写！！！
enum Color{BLACK,RED,GREEN,YELLOW,BLUE,WHITE};
enum Mode{READ=4,WRITE=2,EXECUTE=1,NONE=0};
#define CASEE(e) case e:printf("%s\n", #e);break;
#define PE(e) switch(e){\
				CASEE(READ)\
				CASEE(WRITE)\
				CASEE(EXECUTE)\
				CASEE(NONE)\
	default:printf("unknown\n");break;}
int main()
{
	printf("true=%d, false=%d\n", true, false);
	printf("SD=%d,TS=%d,CSD=%d,DB=%d\n",SD,TS,CSD,DB);
//	enum Gender g;
	ge g;
	g = Male;
	printf("%d\n", g);
	A x="very good!";
	printf("size:%d, %s\n", sizeof(x), x);
	bool ok=true;
	enum Color c;
	printf("ok=%d\n", ok);
	enum Mode m;
	m = WRITE;
	PE(m);
	m = READ;
	PE(m);
	return 0;
}
