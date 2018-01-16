//working with strings
//string.cpp

#include <iostream>
using namespace std;

int main()
{
   string str;
   string substr;
   cout << "please input two strings: ";
   cin >> str >> substr;
   str += str;
   int index = str.find(substr);
   if (index != string::npos)
      cout << "yes" << endl;
   else
      cout << "no" << endl;
   return 0;
}
