// find function exercise

#include <iostream>
#include <string>
using namespace std;

int main()
{
   string s1 = "programming";
   string s2 = "gram";
   int index = s1.find(s2);
   if (index >= 0)
   cout << "found gram at index " << index;
   else
   cout << s2 << " is not a substring";
   return 0;
   }
