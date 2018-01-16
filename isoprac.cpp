// self-practice of lab

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
   const int SIZE=300;
   string discard;
   string names[SIZE];
   string file;

   cout << "Please enter a filename: ";
   cin >> file;

   ifstream instr(file.c_str());
   if (!instr.is_open())
   {
      cout << "Failed to open the file.";
      exit(1);
    }

    getline (instr,discard);
    int count=0;
    while (getline(instr,names[count],';'))
    {
       count++;
       getline (instr,discard);
    }

    cout << "\nThere are " << count << " names.";
    return 0;
}
