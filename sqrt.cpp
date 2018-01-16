/*Modify your program to calculate the square root of the
sum of cubes of numbers in the range using the pow()
function*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   double lower,upper,sum=0.0;
   double sq_rt;
   cout << "Please enter the lower bound of the range: ";
   cin >> lower;
   cout << "Please enter the upper bound of the range: ";
   cin >> upper;

   for ( int i=lower; i <= upper; i++ )
   {
      sum += pow(i,3);
   }

   sq_rt=sqrt(sum);
   cout << "The square root of the sum of cubes is: " << sq_rt;
   return 0;
}
