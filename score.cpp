/*This program prompts the user to enter a series quiz scores
(integer-valued between 0 and 100) and -1 to terminate.
After the user enters -1, display the highest score, the lowest
score and the average of the scores*/

#include <iostream>
using namespace std;

int main()
{
   int score=0,count=0;
   int max=0,min=100;
   double ave=0.0;

   while ( score >= 0 )
   {
      cout << "Enter next score or -1 to quit: ";
      cin >> score;

      if (score >= 0)
      {
        if ( score < min)
         min = score;
        if ( score > max)
         max = score;
        ave += score;
        count++;
      }
   }
ave /= count;

cout << "Top score is " << max << endl;
cout << "Bottom score is " << min << endl;
cout << "Average of scores is " << ave << endl;
return 0;
}
