#include <stdio.h>

int main()
{
	int i, j;//�кź��к�
	int b, e;//�Ǻ�λ��
	int n;//�߳�
	//�Ӽ�������߳�
	printf("������߳�:");
	scanf("%d", &n);
	//����2n��1�Σ�ÿ�δ�ӡһ��
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
	//���
	return 0;
}
