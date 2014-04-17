#include <iostream>
using namespace std;

class myclass
{
private:
	int a;
public:
	myclass( ) {cout << "constructor" << endl; a = 10;}
	~myclass( ) { cout << "destructor" << endl;}
	void show( ) { cout << a << endl;}
};

int  main( )
{
	myclass ob;
	ob.show( );
}
