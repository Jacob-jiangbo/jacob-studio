#include <stdio.h>

int main()
{
        double score, sum=0.0;
        int i;
        printf("������10��ͬѧ�ĳɼ�:\n");
        for(i=0;i<10;++i)
        {
              scanf("%lf", &score);
		if(score<0)
		{
			break;
		}
		if(score>100)
		{
			continue;
		}
                sum += score;
        }
        printf("�ܳɼ�%.1f, ƽ��%.2f\n", sum, sum/10);
        return 0;
}


