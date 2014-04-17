/*  We start with the appropriate headers and then a function, printdir,
    which prints out the current directory.
    It will recurse for subdirectories, using the depth parameter is used for indentation.  */

#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

void printdir(char *dir, int depth)
{
    DIR *dp;
    struct dirent *entry;//定义dirent结构体
    struct stat statbuf;//定义了stat结构体

    if((dp = opendir(dir)) == NULL) {
        fprintf(stderr,"cannot open directory: %s\n", dir);
        return;
    }
    chdir(dir);//相当于cd命令
    while((entry = readdir(dp)) != NULL) {
        lstat(entry->d_name,&statbuf);//作用，将readdir 结构体中的d—name，放入stat 结构体；
        if(S_ISDIR(statbuf.st_mode)) {//调用内部宏函数 S_ISDIR,来判断类型是否为目录
            /* Found a directory, but ignore . and .. */
            if(strcmp(".",entry->d_name) == 0 || 
                strcmp("..",entry->d_name) == 0)
                continue;
            printf("%*s%s/\n",depth,"",entry->d_name);
            /* Recurse at a new indent level */
            printdir(entry->d_name,depth+4);
        }
        else printf("%*s%s\n",depth,"",entry->d_name);
    }
    chdir("..");
    closedir(dp);
}

/*  Now we move onto the main function.  */

int main()
{
    printf("Directory scan of /home:\n");
    printdir("/home",0);
    printf("done.\n");

    exit(0);
}

