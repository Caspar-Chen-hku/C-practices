//assign1P1.cpp
//This program can display a rectangle
//composed of ampersand characters,
//based on the values of height and
//width that the user provides.

#include <iostream>
using namespace std;

int main()
{
  int counter_width,counter_height;

  cout << "width: ";
  cin >> counter_width;
  cout << "height: ";
  cin >> counter_height;

  const int WIDTH = counter_width;

  while (counter_height > 0)
   {
    while (counter_width > 0)
    {
     cout << "&";
     counter_width = counter_width-1;
    }

     cout << endl;
     counter_height = counter_height-1;
     counter_width = WIDTH;
   }
  return 0;
}
