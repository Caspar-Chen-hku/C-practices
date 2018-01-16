/*This program Prompts the user to enter the numbers of rows and columns required;
Display multiples of 1, 2, 3, etc, on consecutive lines as shown in the
sample output on the next slide;
After displaying the table, the user will have the opportunity to enter
'y' or 'Y' to specify new dimensions and display another table. The
user may enter any other character to stop;
After receiving a request to stop, the program will display "Bye for
now!" and terminate*/

#include <iostream>
using namespace std;

void multi_table(int col,int row);

int main()
{
   int col,row;
   char go_on = 'Y';
   cout << "Enter number of rows and columns: ";
   cin >> row >> col;

   while ( go_on == 'Y' || go_on == 'y' )
   {
       multi_table(col,row);

       cout << "\nEnter 'y' or 'Y' to continue. Any other character to stop: ";
       cin >> go_on;

       if ( go_on == 'Y' || go_on == 'y' )
       {
           cout << "\nEnter number of rows and columns: ";
           cin >> row >> col;
       }
        else
           cout << "Bye for now!";
   }
   return 0;
}

void multi_table(int col,int row)
{
    for (int i=1; i <= row; i++)
    {
        for (int j=i; j <= i*col; j += i)
        {
            cout << "\t" << j << "  ";
        }
    cout << endl;
    }
}
