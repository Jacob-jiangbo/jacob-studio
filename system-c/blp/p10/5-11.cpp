#include<iostream>
using namespace std;

class A
{
private:
	int x,y;
public:
	A(int i=0,int j=0) {x=i;y=j;}
	void fun( )	
        {cout<<"��Ա������  x="<<x<<", y="<<y<<endl;}
	void fun( )	const		            //����Ա����
	{cout<<"����Ա������x="<<x<<", y="<<y<<endl;}
};

int main( )
{
	A obj1(1,2);				//A�����
	obj1.fun( );
	const A obj2(3,4);			//A�ೣ����
	obj2.fun( );
}

