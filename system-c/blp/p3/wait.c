//�Ժ�д����Ҫ���������Ľṹ
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t pid;
    char *message;
    int n;
    int exit_code;

    printf("fork program starting\n");
    pid = fork();
    switch(pid) 
    {
    case -1:
        exit(1);
    case 0:
        message = "This is the child";
        n = 5;
        exit_code = 37;//������
        break;
    default:
        message = "This is the parent";
        n = 3;
        exit_code = 0;
        break;
    }

    for(; n > 0; n--) {
        puts(message);
        sleep(1);
    }

/*  This section of the program waits for the child process to finish.  */

    if(pid) {//�������pidΪbool�������Բ��淶
        int stat_val;//�ֲ�����������ջ���棬�����c�ṹ����ʼ�������ڶ��塣������386���ڴ��Ǳ���ģʽ�����Թ۲죬���������������ں̡ܶ�
        pid_t child_pid;//pid_t ���������Ĵ�

        child_pid = wait(&stat_val);//ȡ��������״̬����ʱ�ӽ����Ѿ����ͷ��˺ܶ���

        printf("Child has finished: PID = %d\n", child_pid);
        if(WIFEXITED(stat_val))//�ж��Ƿ������˳�
            printf("Child exited with code %d\n", WEXITSTATUS(stat_val)); //ȡ���˳�ԭ��
        else
            printf("Child terminated abnormally\n");
    }
    exit (exit_code);
}
