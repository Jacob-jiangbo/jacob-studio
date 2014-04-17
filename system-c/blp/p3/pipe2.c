#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int data_processed;
    int file_pipes[2];
    const char some_data[] = "123";
    char buffer[BUFSIZ + 1];//
    pid_t fork_result;

    memset(buffer, '\0', sizeof(buffer));//memsetΪ���ڴ����������ӳ�䵽ϵͳ���ã���Ҫ�ں���ɣ���buffer���㣬�򵥣�����ʹ��

    if (pipe(file_pipes) == 0) {//Ҳ�пո�
        fork_result = fork();
        if (fork_result == -1) {
            fprintf(stderr, "Fork failure");
            exit(EXIT_FAILURE);
        }

// We've made sure the fork worked, so if fork_result equals zero, we're in the child process.

        if (fork_result == 0) {
            data_processed = read(file_pipes[0], buffer, BUFSIZ);//ע��read�е��������Ǵӹܵ�����������
            printf("Read %d bytes: %s\n", data_processed, buffer);
            exit(EXIT_SUCCESS);
        }

// Otherwise, we must be the parent process.

        else {
            data_processed = write(file_pipes[1], some_data,
                                   strlen(some_data));
            printf("Wrote %d bytes\n", data_processed);
        }
    }
    exit(EXIT_SUCCESS);
}
//�ӽ��̲����Լ̳йܵ���ֻ�ǿ��Լ̳��ļ�������
//˭��˭ȡ��ȷ�������Ҫ��ȷ���Ļ�����Ҫ����ͬ����

