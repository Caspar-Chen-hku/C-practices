#include <iostream>
using namespace std;

int main()
{
  const int SIZE=10;
  int deg0,deg1,deg2;
  double p0[SIZE],p1[SIZE];
  double p2[SIZE*2]={};

  cout << "Input the degree of p0: ";
  cin >> deg0;
  cout << "Input the " << deg0+1 << " coefficients of p0: ";
  for ( int i=0; i < deg0+1; i++)
  {
     cin >> p0[i];
  }

  cout << "Input the degree of p1: ";
  cin >> deg1;
  cout << "Input the " << deg1+1 << " coefficients of p1: ";
  for ( int i=0; i < deg1+1; i++)
  {
     cin >> p1[i];
  }

  deg2=deg1+deg0;

  for (int i=0; i<deg0+1; i++)
  {
     for (int j=0; j<deg1+1; j++)
     {
        p2[i+j] += p0[i]*p1[j];
     }
  }

  cout << "The degree of p2 is " << deg2 << endl;
  cout << "The coefficients of p2 are ";
  for ( int i=0; i<deg2+1; i++)
  {
     cout << p2[i] << " ";
  }
  return 0;
}
