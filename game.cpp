//guessing game
//game.cpp

#include <iostream>
using namespace std;

const int TARGET = 66;
int main()
{
   int upper=100,lower=0;
   int count = 0;
   int guess=-1;
   while (guess!=TARGET)
   {
      cout << "Please input a number between " << lower
      << "-" << upper << endl;
      cin >> guess;
      count++;
      if (guess<TARGET)
      {
         lower = guess+1;
         cout << "Try again! ";}
      else if (guess>TARGET)
      {   upper = guess-1;
          cout << "Try again! ";}
      else
      {
         cout << "success! You took " << count << " guess";
         if (count>1)
            cout << "es";
         cout << ".";
      }
    }
    return 0;
}
