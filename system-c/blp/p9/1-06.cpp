// Addition program.
#include <iostream>

// function main begins program execution
int main()
{
   int integer1;  // first number to be input by user
   int integer2;  // second number to be input by user
   int sum;       // variable in which sum will be stored

   std::cout << "Enter first integer\n";  // prompt
   std::cin >> integer1;                  // read an integer

   std::cout << "Enter second integer\n"; // prompt
   std::cin >> integer2;                  // read an integer

   sum = integer1 + integer2;  // assignment result to sum

   std::cout << "Sum is " << sum << std::endl; // print sum

   return 0;   // indicate that program ended successfully

} // end function main
