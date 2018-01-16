//get along with files

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
   const int SIZE = 300;
   string filename;
   cout << "please input the locations filename: ";
   cin >> filename;

   ifstream instream(filename.c_str());
   if (!instream.is_open())
   {
      cout << "Failed to open input file" << endl;
      exit(1);
   }

   string arr[SIZE]={};
   int counter=0;
   while ( getline(instream,arr[counter],';'))
   {
      getline(instream,arr[counter],';');
      counter++;
    }
    cout << "\nThere are " << counter << " names.";
    return 0;
   }
