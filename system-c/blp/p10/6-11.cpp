#include<iostream>
using namespace std;

class ThisSample
{
	int n;
 public:
	ThisSample(){};
	ThisSample(int m)
	{
		n=m;
	};
    void addvalue(int m) //����һ���Ǿ�̬��Ա����
	{
		ThisSample q;
		q.n=n+m;	//�˴�n�൱��this->n
		*this=q;	//����ʱ����q��ֵ���ص��ö���
	};
	void disp()
	{
		cout<<"n="<<n<<endl;
	}
};

int main()
{
	ThisSample s(10);
	s.disp();
	s.addvalue(5);	
	s.disp();
}
