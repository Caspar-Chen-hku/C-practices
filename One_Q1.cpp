//May 19,2015 Q1
//One_Q1.cpp

#include <iostream>
#include <string>
using namespace std;

bool isValid(string input);

int main()
{
   string input;
   getline (cin, input);
   if (isValid (input))
   cout << "valid format" << endl;
   else
   cout << "format not valid" << endl;
   return 0;
}

bool isValid(string input)
{
  while (input.length()!=0)
  {
      if (input[0]=='[' && input.find(']',1)!=string::npos)
      {
          input.erase(0,1);
          input.erase(input.find(']',0),1);
      }
      else if (input[0]=='(' && input.find(')',1)!=string::npos)
      {
          input.erase(0,1);
          input.erase(input.find(')',0),1);
      }
      else
        return false;
  }
  return true;
}

