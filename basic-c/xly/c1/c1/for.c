#include <stdio.h>

int main()
{
        double score, sum=0.0;
        int i;
        printf("请输入10个同学的成绩:\n");
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
        printf("总成绩%.1f, 平均%.2f\n", sum, sum/10);
        return 0;
}


