#include <iostream>
using namespace std;

int mult(int n,int k=2)		//�ڶ����βξ���Ĭ��ֵ
{ 
	if(k==2)
		return (n*n);
	else
		return (mult(n,k-1)*n);
}
int main( )
{
	cout<<endl<<mult(5)<<endl;
	/* �β�n��ʵ������ʼ��Ϊ5���β�k����Ĭ��ֵ2��ʵ��5*5*/
	cout<<mult(5,3)<<endl;
	/* ��ʵ������ʼ���βΣ�nΪ5��kΪ3��ʵ��5*5*5*/
}
