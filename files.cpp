//working with files
//files.cpp

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

int main()
{
   string filename;
   cout << "please input a filename:¡¡";
   cin >> filename;
   ifstream instr(filename.c_str());
   if (!instr.is_open())
   {
      cout << "failed to open the file.";
      exit(1);
   }
   string discard;
   string longstr;
   getline(instr,discard);
   int howlong=0;
   int count = 0;
   while (getline(instr,discard,';'))
   {
      if (discard.length()>howlong)
      {
       longstr = discard;
       howlong = discard.length();
       }
      getline(instr,discard);
      count++;
   }
   cout << "\nThere are " << count << " names." << endl;
   cout << "\nThe longest name is: " << longstr;
   instr.close();
   return 0;
}
