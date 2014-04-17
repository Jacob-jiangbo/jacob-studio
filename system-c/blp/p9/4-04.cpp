#include <iostream>
using namespace std;

class date
{
private:
	int year, month, day;
public:
	date( int y, int m, int d );
	void  print( );
};

date::date(int y, int m, int d )
{
	year = y;
	month = m;
	day = d;
	cout << "constructor called" << endl;
}

void date::print( )
{
	cout << year << "."<< month << "."<< day << endl;
}

int  main( )
{
	date today(2001,8,11), tomorrow(2001,8,12);
	cout << "today is ";
	today.print( );
	cout << "tomorrow is ";
	tomorrow.print( );
}
