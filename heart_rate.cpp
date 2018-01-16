/*Write a program to output the aerobic training
zone limits for runners based on their age.
The aerobic training zone is where heart rate is
between 70%-80% of maximum rate*/

#include <iostream>
using namespace std;

double max_rate (int);
void display_limits (double);

int main()
{
   int age;
   double rate;
   cout << "Please enter your age: ";
   cin >> age;

   rate=max_rate (age);
   display_limits (rate);
   return 0;
}

double max_rate (int age)
{
   int rate = 191.5 - (0.007 * age * age);
   return rate;
}

void display_limits (double rate)
{
   cout << "\nKeep your heart rate between " << rate*0.7
   << "bpm and " << rate*0.8 << "bpm";
}
