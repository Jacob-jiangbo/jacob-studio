/*
fseek(FILE*, ƫ����, �ο���)SEEK_SET,SEEK_CUR,SEEK_END
ftell(FILE*)
rewind(FILE*);��ͬ��fseek(FILE*,0,SEEK_SET);
*/
#include <stdio.h>

int main()
{//15r 20w$ 18w* -1w@ 0
	FILE* fp = fopen("file2", "r+b");
	if(NULL==fp){
		printf("�޷����ļ�file2\n");
		return 1;
	}
	for(;;){
		printf("cmd: ");
		int pos;
		char op;
		char data;
		scanf("%d", &pos);
		if(pos==0) break;
		if(pos==-1) fseek(fp, 0, SEEK_END);
		else fseek(fp, pos-1, SEEK_SET);
		scanf(" %c", &op);
		if(op=='r'){
			printf("%c\n",fgetc(fp));
		}
		else{
			fputc(getchar(), fp);
			fflush(fp);
		}
	}
	fclose(fp);
	return 0;
}
