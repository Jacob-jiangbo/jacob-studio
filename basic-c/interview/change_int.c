#include <stdio.h>
#include <string.h>

void change_int(int * num1, int * num2)
{
    int num = 0;
    num = * num1 + * num2;
    * num1 = num - *num1;
    * num2 = num - *num2;
    return;
}

int main()
{
    int a = 0, b = 0;
    printf("Please input two int\n");
    printf("Input int a\n");
    scanf("%d", &a);
    printf("Input int b\n");
    scanf("%d", &b);

    change_int(&a, &b);

    printf("a=%d,b=%d\n", a, b);

}


