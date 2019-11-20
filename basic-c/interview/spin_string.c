#include <stdio.h>
#include <string.h>

void reverse_left_1(char *str, int n, int len)
{
    int i = 0, j = 0;
    char temp = 0;

    n %= len;//判断左旋的有效次数
    for (i = 0; i < n; i++)//左旋的总次数
    {
        temp = str[0];//保存第一个元素
        for (j = 0; j < len - 1; j++)//左旋一次
        {
            str[j] = str[j + 1];//将后一位元素放置其前一位
        }
        str[j] = temp;//将第一个放置最后一个，完成左旋一次后的结果
    }
}

int main()
{
    char str[] = "abcd1234";
    int n = 0, len = strlen(str);

    printf("please enter->");
    scanf("%d", &n);//输入左旋的次数
    printf("before reverse_left string is :%s\n", str);
    reverse_left_1(str, n, len);
    printf("reverse_left string is :%s\n", str);

    system("pause");
    return 0;
}


