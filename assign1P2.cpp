//assign1P2.cpp
//The user is prompted to enter two integers
//and several divisors,and this program will
//display all the integers between the entered
//ones,highlighting the ones divisible by the
//divisors with ampersand characters.

#include <iostream>
using namespace std;

int main ()
{
    int a,b;
    int divisor_one = -1;
    int divisor_two = -1;
    int divisor_three = -1;
    int divisor_four = -1;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;

    int num = a+1;

    cout << "Add divisor: ";
    cin >> divisor_one;
    if (divisor_one > 0)
    {
        cout << "Add divisor: ";
        cin >> divisor_two;
        if (divisor_two > 0)
        {
            cout << "Add divisor: ";
            cin >> divisor_three;
            if (divisor_three > 0)
            {
                cout << "Add divisor: ";
                cin >> divisor_four;
                if (divisor_four > 0)
                    cout << "Add divisor: -1" << endl;

            }
        }
    }
        while ( num<b )
        {
            cout << num;
            if ( num%divisor_one==0 && divisor_one>0 )
                cout << "& ";
            else if ( num%divisor_two==0 && divisor_two>0 )
                cout << "& ";
            else if ( num%divisor_three==0 && divisor_three>0 )
                cout << "& ";
            else if ( num%divisor_four==0 && divisor_four>0 )
                cout << "& ";
            else
                cout << " ";
            num = num+1;
        }
    cout << endl;
    return 0;
}

