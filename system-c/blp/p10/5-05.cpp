#include<iostream>
using namespace std;

class Test
{
private:
	int k;
public:
	static int n;				//静态数据成员
	Test(int kk) {
            k=kk; 
            n++; 
        }
	void Display( ) {
            cout<<"n="<<n<<" k="<<k<<endl;
        }
};

int Test::n=0;		//静态数据成员初始化
int main( ) 
{
	Test t1(10);
	t1.Display( );
	Test t2(20);
	t2.Display( );
	Test::n++;
	t2.Display( );
}

