//This program outputs rectangles according to
//the user's input

#include <iostream>
using namespace std;

int main()
{
   int width,height;
   cout << "Width: ";
   cin >> width;
   cout << "Height: ";
   cin >> height;
   for (int i=0; i<height; i++)
   {
      for (int j=0; j<width; j++)
      {
         cout << "&";
      }
      cout << endl;
   }
   return 0;
}
