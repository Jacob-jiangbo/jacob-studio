 #include <stdio.h>
int main()
{//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	char ch;
//menu:
	do{
		puts("1--һ���˲�5000");
		puts("2--�����˲�3000");
		puts("3--�����˲�2000");
		puts("4--�ļ��˲�1000");
		puts("5--�弶�˲����");
		puts("0--�˳�");
		scanf(" %c", &ch);
//		char c;do{scanf("%c",&c);}while(c!='\n');
	}while((ch<'0'||ch>'5')&&printf("��Чѡ��\n"));
//	if(ch<'0'||ch>'5') goto menu;
	printf("��ѡ�����%c\n", ch);
	return 0;
}
//;;;;;;;;;;;;;;;;;;;;;;;;;;

