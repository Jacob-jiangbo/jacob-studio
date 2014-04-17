// Using if statements, relational
// operators, and equality operators.
#include <iostream>

using std::cout;  // program uses cout
using std::cin;   // program uses cin
using std::endl;  // program uses endl

// function main begins program execution
int main()
{
   int num1;  // first number to be read from user
   int num2;  // second number to be read from user

   cout << "Enter two integers, and I will tell you\n"
        << "the relationships they satisfy: ";
   cin >> num1 >> num2;   // read two integers

   if ( num1 == num2 )
      cout << num1 << " is equal to " << num2 << endl;

   if ( num1 != num2 )
      cout << num1 << " is not equal to " << num2 << endl;

   if ( num1 < num2 )
      cout << num1 << " is less than " << num2 << endl;

   if ( num1 > num2 )
      cout << num1 << " is greater than " << num2 << endl;

   if ( num1 <= num2 )
      cout << num1 << " is less than or equal to "
           << num2 << endl;

   if ( num1 >= num2 )
      cout << num1 << " is greater than or equal to "
           << num2 << endl;

   return 0;   // indicate that program ended successfully

} // end function main
