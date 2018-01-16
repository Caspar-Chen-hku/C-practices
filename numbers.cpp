//numbers.cpp
//this program deals with numbers

#include <iostream>
using namespace std;

int main()
{
int counter=0,sump=0;
int sumn=0,sum=0;
while ( counter<10 )
 {
  int num;
  cin >> num;
  if ( num>0 )
  {
   sump = sump+num;
   }
  else
   {
   sumn = sumn+num;
   }
  sum = sum+num;
  counter++;
 }
cout << "The sum of the positive numbers = " << sump << endl;
cout << "The sum of the negative numbers = " << sumn << endl;
cout << "The sum of the numbers = " << sum << endl;
return 0;
}


