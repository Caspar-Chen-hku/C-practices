//1D array practice
//arr1.cpp

#include <iostream>
using namespace std;

int main()
{
   int arr[8];
   double sum=0.0;
   cout << "Please input 8 integers: ";
   for (int i=0; i<8; i++)
   {
      cin >> arr[i];
      sum += arr[i];
   }
   double ave = sum/8;
   int count = 0;
   for (int i=0; i<8; i++)
   {
      if (arr[i]<ave)
         count++;
   }
   cout << "There are " << count << " numbers smaller than the mean.";
   return 0;
}
