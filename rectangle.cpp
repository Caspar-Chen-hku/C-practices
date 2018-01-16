//rectangle.cpp
//This program is meant to calculate the perimeter and the area of the rectangle

#include <iostream>
using namespace std;

int main()
{
int length,width;
cout << "Please input the sides of the rectangle:";
cin >> length >> width;

int peri = length+width;
int area = length*width;

cout << "The perimeter of the rectangle is: " << peri << endl;
cout << "The area of the rectangle is: " << area << endl;
return 0;
}

