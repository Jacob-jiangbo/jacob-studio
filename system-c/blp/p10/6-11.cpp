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
    void addvalue(int m) //定义一个非静态成员函数
	{
		ThisSample q;
		q.n=n+m;	//此处n相当于this->n
		*this=q;	//将临时对象q的值传回调用对象
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
