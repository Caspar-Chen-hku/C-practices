//numbers2.cpp
//this program is an updated one of numbers.cpp

#include <iostream>
using namespace std;

int main()
{
int counter=0,sump=0,sumn=0;
int sum=0,nump=0,numn=0;

while (counter<10)
 {
  int num;
  cin >> num;
  if ( num>0 )
  {
   sump += num;
   nump++;
   }
  else
   {
   sumn += num;
   numn++;
   }
  sum += num;
  counter++;
 }
double asump,asumn,asum;
if ( nump=0 )
    {
    asump = 0;
    asumn = sumn/10.0;
    }
else if ( nump=10 )
    {
    asumn = 0;
    asump = sump/10.0;
    }
else
    {
    asump = 1.0*sump/nump;
    asumn = 1.0*sumn/numn;
    }
asum = sum/10.0;

cout << "The sum of the positive numbers = " << sump << endl;
cout << "The average of the positive numbers = " << asump << endl;
cout << "The sum of the non-positive numbers = " << sumn << endl;
cout << "The average of the non-positive numbers = " << asumn << endl;
cout << "The sum of the numbers = " << sum << endl;
cout << "The average of the numbers = " << asum << endl;
return 0;
}
