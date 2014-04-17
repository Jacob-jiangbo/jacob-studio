#include <iostream>
using namespace std;

int add(int x,int y) 
{
	int sum;
	sum=x+y;
	return(sum);
}

int add(int x,int y,int z)
{
	int sum;
	sum=x+y+z;
	return(sum);
}
int main( )
{
	int a, b;
	a=add(5,10);
	b=add(5,10,20);
	cout<<"a="<<a<<" b="<<b<<endl;
}
