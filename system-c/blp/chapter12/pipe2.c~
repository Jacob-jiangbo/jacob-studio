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

    memset(buffer, '\0', sizeof(buffer));//memset为对内存操作函数，映射到系统调用，主要内核完成，把buffer清零，简单，建议使用

    if (pipe(file_pipes) == 0) {//也有空格
        fork_result = fork();
        if (fork_result == -1) {
            fprintf(stderr, "Fork failure");
            exit(EXIT_FAILURE);
        }

// We've made sure the fork worked, so if fork_result equals zero, we're in the child process.

        if (fork_result == 0) {
            data_processed = read(file_pipes[0], buffer, BUFSIZ);//注意read中的描述符是从管道函数中来的
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
//子进程不可以继承管道，只是可以继承文件描述符
//谁读谁取不确定。如果要是确定的话，就要进程同步。

