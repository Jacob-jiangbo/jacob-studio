#include <stdio.h>
int main()
{
	puts("a--java");
	puts("b--c++");
	puts("c--Ƕ��ʽ");
	puts("d--���ݿ�");
	puts("e--����");
	puts("q--�˳�");
	printf("��ѡ��:");
	char choice;
	scanf(" %c", &choice);
	if(choice=='q'){
		puts("лл����");
	}
	else
	{
		switch(choice)
		{
			case 'a':
				puts("����java������");break;
			case 'b':
				puts("����C++������");break;
			case 'c':
				puts("����Ƕ��ʽ������");break;
			case 'd':
				puts("�������ݿ������");break;
			case 'e':
				puts("���ܲ��԰�����");break;
			default:
				puts("��Ч��ѡ��");break;
		}
	}
	return 0;
}

