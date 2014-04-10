#include <stdio.h>
//print format
/*
%d,%i 用整数的十进制格式来代替
%x,%X,%o 用整数的十六进制和八进制格式来代替
%e,%f,%E,%g 用小数来代替
%s 用字符串来代替
%c 用一个字符来代替
%% 用一个%来代替
*/
int main()
{
	printf("abc%def%ghi%%jk\n",123,456*1.0);
	printf("姓名:%s\n性别:%c\n年龄:%d\n住址:%s\n",
		"陈宗权", 'M', 40, "中国北京");
	return 0;
}

