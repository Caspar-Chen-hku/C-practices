//self-practice problem
//this program is about outputing a table with
//temporatures in celcius with a certain range
//and certain step

#include <iostream>
using namespace std;

void display(int upper,int lower,int step);
int main()
{
   int lower,upper,step;
   cout << "Please enter the upper bound and " << endl;
   cout << "the lower bound of certain temporatures: ";
   cin >> upper >> lower;
   cout << "Please enter the step: ";
   cin >> step;

   display (upper,lower,step);
   return 0;
}

void display(int upper,int lower,int step)
{
   for(int i=lower; i<=upper; i += step)
   {
      cout << i << " ";
   }
}
