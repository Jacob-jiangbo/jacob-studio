#include <stdio.h>
int main()
{
	puts("1--һ���˲�5000");
	puts("2--�����˲�3000");
	puts("3--�����˲�2000");
	puts("4--�ļ��˲�1000");
	puts("5--�弶�˲����");
	puts("0--�˳�");
	printf("��ѡ��:");
	int ch;
	if(scanf(" %d", &ch)!=1)
		puts("û�гɹ�����!");
	printf("ch=%d\n", ch);
	if(ch==0) puts("��ӭ�´�����");
	else{
		switch(ch){
			case 1:puts("�븶5000Ԫ");break;
			case 2:puts("�븶3000Ԫ");break;
			case 3:puts("�븶2000Ԫ");break;
			case 4:puts("�븶1000Ԫ");break;
			case 5:puts("���");break;
			default:puts("��Чѡ��");break;
		}
	}
	return 0;
}

