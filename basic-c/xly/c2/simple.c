#include <stdio.h>

int last(void)//��������
{
	printf("��ӭʹ���Զ��庯��last!\n");
	return 0;
}
double func();//��������
int isleap(int year)
{
	if(year%4==0&&year%100!=0||year%400==0) return 1;
	else return 0;
}
int days(int year/*�β�1*/, int month/*�β�2*/)//������
{
	if(month==4||month==6||month==9||month==11)
		return 30;
	else if(month==2)
		return isleap(year)+28;
	else
		return 31;
}
void print_diamond(int n)
{
	int i, j;
	int b, e;
        for(i=1; i<2*n; i++)
        {
                //���㱾�е��Ǻ�λ��
                b = (i<=n?(n-i+1):(i-n+1));
                e = 2*n - b;
                //����2n��1�Σ�ÿ�δ�ӡһ��
                for(j=1; j<2*n; j++)
                {
                        //������Ǻ�λ�þʹ��Ǻţ�
                        //if(j==b||j==e) printf("*");//��ӡ��������
                        if(j>=b&&j<=e) printf("*");//��ӡʵ������
                        //����ʹ�ո�
                        else printf(" ");
                }
                //��ӡ���з�
                printf("\n");
        }
	//return;���п��ޣ���return����������ݣ���Ϊ����������void
}
int main()
{
	func();//��������
	printf("��ӭʹ��main����!\n");//��������
	printf("%g\n", func());//��������
	last();//��������
	printf("%d\n", isleap(2010));
	printf("%d\n", isleap(2008));
	printf("%d\n", days(2010,7));//���ú��������ݵ����ݽ�ʵ��
	print_diamond(5);
	print_diamond(4);
	//func(3,5,7,"hello",123.456);������Ϊ�գ���ͨ������
	//last(3);��������void������ͨ������
	//printf("%d", print_diamond(3));����������void�������ؽ��
	return 0;
}
double func()//��������
{
	printf("��ӭʹ���Զ��庯��func!\n");
	return 1230.5;
}
/*
�������β��Լ������������������������ÿ�ε��õ�ʱ���·����ڴ�ռ䣬���������������ʱ����ռ���ջء������������ٴα����ã����ٷ���һ���µ��ڴ�ռ䣬��Ӱ��ɵ���һ��
*/
