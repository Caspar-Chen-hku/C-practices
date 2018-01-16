//divisor within a range

#include <iostream>
using namespace std;

const int SIZE = 4;
bool dividable(int i, int divisor[], int count);
int main()
{
   int a,b;
   cout << "a: ";
   cin >> a;
   cout << "b: ";
   cin >> b;

   int divisor[SIZE];
   cout << "Add divisor: ";
   cin >> divisor[0];
   int count=0;
   while (divisor[count]>0)
   {
      count++;
      cout << "Add divisor: ";
      cin >> divisor[count];
   }
   int counter=0;
   for (int i=a+1; i<b; i++)
   {
      cout << i;
      if (dividable(i,divisor,count))
      {
         cout << "&";
      }
      if (i<b-1)
         cout << ' ';
   }
   cout <<endl;
}

bool dividable(int i, int divisor[], int count)
{
    for (int j=0; j<count; j++)
    {
        if (i%divisor[j]==0)
            return true;
    }
    return false;
}
