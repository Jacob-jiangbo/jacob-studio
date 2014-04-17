//以后写进程要采用这样的结构
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
        exit_code = 37;//返回码
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

    if(pid) {//容易理解pid为bool量，所以不规范
        int stat_val;//局部变量定义在栈里面，合理的c结构，开始声明，在定义。但是在386，内存是保护模式。可以观察，两个变量的生存期很短。
        pid_t child_pid;//pid_t 被定义了四次

        child_pid = wait(&stat_val);//取出结束的状态，此时子进程已经被释放了很多了

        printf("Child has finished: PID = %d\n", child_pid);
        if(WIFEXITED(stat_val))//判断是否正常退出
            printf("Child exited with code %d\n", WEXITSTATUS(stat_val)); //取出退出原因
        else
            printf("Child terminated abnormally\n");
    }
    exit (exit_code);
}
