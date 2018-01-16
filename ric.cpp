//ticket

#include <iostream>
using namespace std;

int main()
{
   int ticket=50;
   int want;
   while (ticket>0)
   {
      cout << "How many tickets do you want? ";
      cin >> want;
      if (want>ticket)
         cout << "Sorry, we don't have enough tickets." << endl;
      else if (want<=0 || want>9)
         cout << "Number of tickets requested must be from 1 to 9." << endl;
      else
      {
         ticket -= want;
         cout << "Remaining tickets: " << ticket << endl;
      }
   }
   cout << "All tickets sold!";
   return 0;
}
