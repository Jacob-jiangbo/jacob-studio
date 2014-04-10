#include <stdio.h>

int main()
{
	char name[]="chenzongquan";
	char* p = name;//p保存的是字符'c'的地址
	int i;
	for(i=0; i<5; i++)
		printf("%s\n", p+i);
	p = "jsd1006";//p保存的是字符'j'的地址
	printf("%s\n", p);
	//*p = 'J';可能会导致段错误
	//printf("%s\n", p);
	//scanf("%s", p);可能会导致段错误
	char* r = NULL;//空指针r，NULL就是0，不会是任何一个变量的地址
	//char* q;//野指针q，里面保存的是一个不可预知的地址
	//scanf("%s", q);//输入一个字符串保存到q表示的地址去，结果靠你的运气
	char* x[5]={"abc","defghi","ha ha","lalala","k"};
	for(i=0; i<5; i++)
		printf("%s\n", x[i]);//puts(x[i]);
	return 0;
}

