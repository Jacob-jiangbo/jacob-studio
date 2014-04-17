#include<iostream>
using namespace std;

int k;

int main( )
{
    k=10; 
    {
        int k=5;
        cout<<"k="<<k<<endl; 
    }
    cout<<"k="<<k<<endl;
}
