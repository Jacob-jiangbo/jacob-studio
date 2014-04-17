#include <iostream>
using namespace std;

int mult(int n,int k=2)		//第二个形参具有默认值
{ 
	if(k==2)
		return (n*n);
	else
		return (mult(n,k-1)*n);
}
int main( )
{
	cout<<endl<<mult(5)<<endl;
	/* 形参n用实参来初始化为5，形参k采用默认值2，实现5*5*/
	cout<<mult(5,3)<<endl;
	/* 用实参来初始化形参，n为5，k为3，实现5*5*5*/
}
