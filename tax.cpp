//tax.cpp
//how much tax do you need to offer?

#include <iostream>
using namespace std;

int main()
{
int first_num,first_rate;
cout << "1st bracket and rate:";
cin >> first_num >> first_rate;

int v = first_num*first_rate*0.01;

int second_num,second_rate;
cout << "2nd bracket and rate:";
cin >> second_num >> second_rate;

int u = second_num*second_rate*0.01;

int third_num,third_rate;
cout << "3rd bracket and rate:";
cin >> third_num >> third_rate;

int w = third_num*third_rate*0.01;

int rfr;
cout << "Rate for remainder:";
cin >> rfr;

int inc;
cout << "Enter income (must exceed $120000):";
cin >> inc;

int x = inc-120000;
int tax = v+u+w+rfr*x*0.01;
cout << "Tax is $" << tax;
return 0;
}

