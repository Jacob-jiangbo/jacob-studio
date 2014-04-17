#include <iostream>
using namespace std;

class date
{
private:
	int year,month,day;
public:
	date( int y,int m,int d );
	void print( );
};

date::date(int y=2000, int m=1, int d=1 )
{
	year = y;
	month = m;
	day = d;
}

void date::print( )
{
	cout << year << "."<< month << "."<< day << endl;
}

int main( )
{
	date days[4]={
			date(2010,8,11),date(2001,8,12),date(2001,8,13)
			,date(2001,8,14)};
	for (int i=0; i<4; i++)
		days[i].print( );
}
