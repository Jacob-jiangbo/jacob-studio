#include<iostream>
using namespace std;

class A
{
private:
	int x,y;
public:
	A(int i=0,int j=0) {x=i;y=j;}
	void fun( )	
        {cout<<"成员函数：  x="<<x<<", y="<<y<<endl;}
	void fun( )	const		            //常成员函数
	{cout<<"常成员函数：x="<<x<<", y="<<y<<endl;}
};

int main( )
{
	A obj1(1,2);				//A类对象
	obj1.fun( );
	const A obj2(3,4);			//A类常对象
	obj2.fun( );
}

