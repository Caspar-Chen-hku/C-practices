/*This program, given a positive integer as input, will determine whether or
not the integer is a prime number and will output is prime or is not prime
accordingly*/

#include <iostream>
using namespace std;

int main()
{
   int num;
   cout << "Integer to test: ";
   cin >> num;

   for (int i=2; i<num; i++)
   {
      if ( num%i == 0)
      {
         cout << "\n" << num << " is not prime";
         return 0;
      }
   }

   cout << "\n" << num << " is prime";
   return 0;
}
