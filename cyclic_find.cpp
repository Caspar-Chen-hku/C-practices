//cyclic find

#include <string>
#include <iostream>
using namespace std;

int main()
{
   string s1,s2;
   cout << "please input the two strings: ";
   cin >> s1 >> s2;

   string str1 = s1 + s1;
   int index = str1.find(s2);
   if ( index >= 0)
     cout << s2 << " is a cyclic string of " << s1;
   else
     cout << s2 << " is not a cyclic string of " << s1;
   return 0;
}
