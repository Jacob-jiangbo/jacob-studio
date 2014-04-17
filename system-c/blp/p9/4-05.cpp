#include <iostream>
using namespace std;

class point
{
private:
	int x, y;
public:
	point(int xx = 0, int yy = 0) {x = xx; y = yy;}
	point(point &p);
	int get_x( ) {return x;}
	int get_y( ) {return y;}
};

point::point(point &p)
{
	x = p.x;
	y = p.y;
	cout << "拷贝构造函数被调用"<< endl;
}

void f ( point p)
{
    cout << p.get_x( ) << " " << p.get_y( ) << endl;
}

int main ( )
{
	point a(15, 22);
	point b( a );
 	cout << b.get_x( ) << " " << b.get_y( ) << endl;
	f (b);
}
