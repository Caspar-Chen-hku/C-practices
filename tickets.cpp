//tickets.cpp
//this program keeps track of the unsold tickets

#include <iostream>
using namespace std;

int main()
{
int ticket = 50;
int want;
while ( ticket>0 )
 {
 cout << "How many tickets do you want? ";
 cin >> want;
 if ((want>=1)&&(want<=9))
  {
   if ( ticket>=want )
   {
    ticket -= want;
    cout << "Remaining tickets: " << ticket << endl;
   }
   else
   cout << "Sorry,we don't have enough tickets." << endl;
  }
  else
  cout << "Number of tickets requested must be from 1 to 9." << endl;
 }
cout << "All tickets sold!";
return 0;
}
