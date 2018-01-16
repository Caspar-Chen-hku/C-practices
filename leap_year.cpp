/* This program prompts the user to input a
year (or any negative number to quit) and then determines whether or
not the year is a leap year.
The program will loop until the user enters a negative number*/

#include <iostream>
using namespace std;

int main()
{
   int year;
   cout << "Enter a year (or negative number to quit): ";
   cin >> year;

   while ( year > 0 )
   {
      if ( year%4 == 0 && year%100 != 0 || year%400 == 0)
         cout << year << " is a leap year" << endl;
      else
         cout << year << " is not a leap year" << endl;

      cout << "\nEnter a year (or negative number to quit): ";
      cin >> year;
   }
cout << "\nBye!!";
return 0;
}
