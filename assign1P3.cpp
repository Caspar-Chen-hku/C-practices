//assign1P3.cpp
//This program displays two triangles
//composed of ampersand characters,
//based on the value of height
//that the user provides.

#include <iostream>
using namespace std;

int main()
{
    int height;
    cout << "height: ";
    cin >> height;

    int counter = 1;
    int count_blank = 2*height;

    while (counter <= height)
    {
        int num = counter;
        int real_blank = count_blank;

        while (counter > 0)
        {
            cout << "&";
            counter = counter-1;
        }
        while (count_blank > 0)
        {
            cout << " ";
            count_blank = count_blank-1;
        }

        count_blank = real_blank;
        counter = num;

        while (counter > 0)
        {
            cout << "&";
            counter = counter-1;
        }

        cout<<endl;
        counter = num+1;
        count_blank = real_blank-2;
    }
return 0;
}
