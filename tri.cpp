//display triangles according to the input

#include <iostream>
using namespace std;

int main()
{
   int h;
   cout << "height: ";
   cin >> h;
   int space;
   for (int i=1; i<=h; i++)
   {
      space = 2*h+2-2*i;
      for (int j=0; j<i; j++)
      {
         cout << "&";
      }
      for (int j=0; j<space; j++)
      {
         cout << ' ';
      }
      for (int j=0; j<i; j++)
      {
         cout << "&";
      }
      cout << endl;
   }
   return 0;
}
