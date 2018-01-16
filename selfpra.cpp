//self-practice problem
//This program deals with the permutation
//of a string input by the user

#include <iostream>
#include <string>
using namespace std;

int main()
{
   string str;
   cout << "Please input a string: ";
   cin >> str;
   int len = str.length();
   cout << str << endl;

   for (int i = len-2; i >= 0; i--)
   {
      for (int j = i+1; j < len; j++)
      {
         char tem = str.at(j);
         str.at(j) = str.at(i);
         str.at(i) = tem;
         cout << str << endl;
         }
   }

   return 0;
   }
