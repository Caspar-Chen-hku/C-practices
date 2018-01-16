//square.cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
   int h;
   cout << "Please input the height: ";
   cin >> h;

   ofstream out("square.txt");
   if (!out.is_open())
   {
      cout << "Failed to open the file.";
      exit(1);
   }
   for (int i=0; i<h; i++)
   {
      for (int j=0; j<h; j++)
      {
         out << "*";
      }
      out << endl;
   }
   out.close();
   return 0;
}
