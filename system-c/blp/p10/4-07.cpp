#include <iostream>
using namespace std;

class A
{
private:
	int a1, a2;
public:
	A(int i, int j) {a1=i, a2=j;}
	void print( ) {cout<<a1<<","<<a2<<endl;}
};

class B
{
private:
	A a;
	int b;
public:
	B(int i, int j, int k): a(i,j), b(k) {}//ÐÎ²Î±í
	void print( );
};

void B::print( ) {
	a.print( );
	cout << b << endl;
}

int main( )
{
	B b(3, 4, 5);
	b.print( );
}

