//working with dynamic arrays
//dynamic.cpp

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

struct NameCode{
   string name;
   string code;
};

void display(NameCode arr[], int num);
int search(NameCode arr[], int num, string nname);
void sort(NameCode arr[], int num);
void swap(NameCode &i, NameCode &j);

int main()
{
   string filename;
   cout << "Please enter a filename: ";
   cin >> filename;
   ifstream instr(filename.c_str());
   if (!instr.is_open())
   {
      cout << "Failed to open the file.";
      exit(1);
   }
   string discard;
   getline(instr,discard);
   getline(instr,discard,'>');
   int num;
   instr >> num;
   instr.ignore();

   NameCode* arr = new NameCode[num];
   for (int i=0; i<num; i++)
   {
       getline(instr,arr[i].name,';');
       getline(instr,arr[i].code);
   }
    display(arr,num);

    NameCode nnamecode;
    cout << "Please input a new pair of name and code: ";
    cin >> nnamecode.name >> nnamecode.code;
    int index = search(arr,num,nnamecode.name);

    NameCode* ptr = arr;
    arr = new NameCode[num+1];
    for (int i=0; i<index; i++)
    {
       arr[i] = ptr[i];
    }
    arr[index] = nnamecode;
    for (int i=index+1; i<=num; i++)
    {
       arr[i]=ptr[i-1];
    }
    display(arr,num+1);

    sort(arr,num+1);
    display(arr,num+1);

    delete []arr;
    arr = 0;
    delete []ptr;
    ptr = 0;
   instr.close();
    return 0;
}

void display(NameCode arr[], int num)
{
   for (int i=0; i<num; i++)
   {
     cout << arr[i].name << '\t' << arr[i].code << endl;
   }
   cout << endl;
}

int search(NameCode arr[], int num, string nname)
{
   int index=0;
   for (int i=0; i<num; i++)
   {
      if (arr[i].name<nname)
         index++;
   }
   return index;
}

void sort(NameCode arr[], int num)
{
    NameCode shortest;
    int shortlength;
    int index;
    for (int i=0; i<num-1; i++)
    {
        shortlength = arr[i].name.length();
        index = i;
        for (int j=i+1; j<num; j++)
        {
            if (arr[j].name.length()<shortlength)
            {
                shortlength = arr[j].name.length();
                index = j;
            }
        }
        swap(arr[i],arr[index]);
    }
}

void swap(NameCode &i, NameCode &j)
{
    NameCode temp = i;
    i = j;
    j = temp;
}
