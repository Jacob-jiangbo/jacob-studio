#include<iostream>
using namespace std;

int main( )
{
	int n=5;
	const int &m;			//声明m为常引用
	m=10;
	cout<<"m="<<m<<endl;
}

