#include <iostream>
#include <iomanip>
using namespace std;

inline int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int main( )
{
	int a,b,c,d;
	a=210;
	b=150;
	c=20;
	d=max(a,b);
	d=max(d,c);
	//����ʱ�������ô������滻Ϊmax��������䡣
	cout<<"The biggest of"
	<<setw(5)<<a
	<<setw(5)<<b
<<setw(5)<<c<<" is "<<d<<endl;
}
