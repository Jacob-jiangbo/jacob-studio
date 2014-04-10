//标准IO，控制台IO，从键盘读取（输入），向屏幕写（输出）
//格式化：scanf,printf
//格式占位符:c,hd,d(i跟d相同),x,o,ld,f,lf,g(简化),e(科学记数法)
//宽度（默认用实际宽度）和填充（默认用空格）
//精度(.n)表示小数点后n位
//对齐(-)
//非格式化：getchar/gets, putchar/puts
//%s,%p
//对于字符串输出，用精度表示最多输出多少个字符
//输入时：格式占位符严格要求类型匹配，非格式占位符的字符要求用户输入时原样输入，非格式占位符如果是空白字符（一般用空格）则不是要求用户输入时原样输入而是程序读取用户输入的数据时跳过空白字符（空格、制表符和换行符)直到非空白字符为止。特别说明：在scanf格式串末尾不要带'\n'！！
//输入时，scanf的格式串%c前面几乎总是带个空格" %c"以便跳过空白字符
//%[]读取在方括号指定范围内的字符
#include <stdio.h>
int main()
{
	printf("%c,%i,%x,%o,%f,%e,%g\n",122,122,122,122,
		   123.5,123.5,123.5);
	printf("%10c,%10d,%20f\n",122,122,123.5);
	printf("%10c,%010d,%020f\n",122,122,123.5);
	printf("%-10c,%-10d,%-20f\n",122,122,123.5);
	printf("%20.2f,%.2f\n", 123.456,123.453);
	const char* str = "hello";
	printf("%s, %p\n", str, str);
	printf("%10s\n", str);
	printf("%10.3s\n", str);
	int n;
	printf("input an integer(n=):");
//	scanf("%2d", &n);
	scanf("n=%d", &n);
	printf("n:%d\n", n);
	char buf[100], buf2[100];
	printf("input a string:");
	scanf(" %[a-j]%[^a-j]", buf, buf2);
	printf("buf=%s, buf2=%s\n", buf, buf2);
	scanf("%[^\n]%*c", buf);
	//scanf("%[^\n]%*c", buf2);
	scanf("%[^\n]", buf2);
	printf("buf=%s, buf2=%s\n", buf, buf2);
	return 0;
}
