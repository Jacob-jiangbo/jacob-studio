#include <stdio.h>
#include <unistd.h>

int main()
{
	int i;
	if(fork()==0){
		for(i=0; i<1; i++)
		printf("����a���ҵĽ���id%d��������%d\n", getpid(), getppid());
	}
	else if(fork()==0){
		for(i=0; i<1; i++)
		printf("����b���ҵĽ���id%d��������%d\n", getpid(), getppid());
	}
	else if(fork()==0){
		for(i=0; i<1; i++)
		printf("����c���ҵĽ���id%d��������%d\n", getpid(), getppid());
	}
	else {
		for(i=0; i<1; i++)
		printf("���Ǹ�����%d\n", getpid());
	}
	return 0;
}

\n", getpid(), getppid());
	}
	else if(fork()==0){
		for(i=0; i<5; i++,sleep(1))
		printf("����c���ҵĽ���id%d��������%d\n", getpid(), getppid());
	}
	else {
		for(i=0; i<20; i++,sleep(1))
		printf("���Ǹ�����%d\n", getpid());
	}
	return 0;
}

