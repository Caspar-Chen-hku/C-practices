//working with structured data
//struct.cpp

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

struct NameCode{
  string name;
  string code;
};

void display_embedded_names(NameCode arr[], int size);
void display_nonmatch_codes(NameCode arr[], int size);
void display_code_not_present(NameCode arr[], int size);

int main()
{
   string filename;
   cout << "please input a filename: ";
   cin >> filename;
   ifstream instr(filename.c_str());
   if (!instr.is_open())
   {
      cout << "failed to open the file.";
      exit(1);
   }
   string discard;
   NameCode arr[300];
   getline(instr,discard);
   int count = 0;
   NameCode longest;
   int howlong = 0;
   while (getline(instr,arr[count].name,';'))
   {
      getline(instr,arr[count].code);
      if (arr[count].name.length() > howlong)
      {
         howlong = arr[count].name.length();
         longest = arr[count];
      }
      count++;
   }
   int num = count;
   cout << "\nThere are " << num << " names." << endl;
   cout << "\nThe longest name is: " << longest.name << endl;
   cout << "Its code is " << longest.code << endl;

   display_embedded_names(arr, num);
   display_nonmatch_codes(arr, num);
   display_code_not_present(arr, num);

   return 0;
}

void display_embedded_names(NameCode arr[], int size)
{
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            if (arr[i].name.find(arr[j].name)!=string::npos && i!=j)
            {
                cout << "\nThe name " << arr[j].name
                << " appears in " << arr[i].name;
            }
        }
    }
    cout << endl;
}

void display_nonmatch_codes(NameCode arr[], int size)
{
    for (int i=0; i<size; i++)
    {
        if (arr[i].name.find_first_of(arr[i].code,0)==string::npos)
        {
            cout << "\nNo letter of the code " << arr[i].code
            << " appears in " << arr[i].name;
        }
    }
    cout << endl;
}

void display_code_not_present(NameCode arr[], int size)
{
    int index;
    for (int i=0; i<size; i++)
    {
        index = arr[i].name.find(arr[i].code.at(0));
        if (index!=string::npos)
        {
            if (arr[i].name.find(arr[i].code.at(1),index+1)==string::npos)
            {
                cout << "\nLetters of code " << arr[i].code << " not present"
                << " in order in " << arr[i].name;
            }
        }
        else
        {
            cout << "\nLetters of code " << arr[i].code << " not present"
                << " in order in " << arr[i].name;
        }
    }
    cout << endl;
}
