/*Write a program to do the following:
Read 8 integers from standard input
Report how many are less than the mean*/

#include <iostream>
using namespace std;

int main()
{
   int arr[8];
   int count=0;
   double mean=0.0;
   cout << "Please enter 8 integers: ";
   for (int i=0; i<8; i++)
   {
      cin >> arr[i];
      mean += arr[i];
   }

   mean /= 8;
   for (int i=0; i<8; i++)
   {
      if (arr[i]<mean)
      {
         count++;
      }
   }
   cout << "There are " << count << " integers less than the mean";
   return 0;
}
