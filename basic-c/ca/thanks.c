#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[])
{
	if(argc==1){
		printf("�÷�:\n\t%s ���� ...\n", argv[0]);
		return 0;
	}
	if(strcmp(argv[0],"thanks")!=0){
		printf("��ʹ���������!\n");
		remove(argv[0]);
		return 0;
	}
	int i;
	for(i=1; i<argc; i++)
		printf("��л�㣬%s��\n", argv[i]);
	return 0;
}
