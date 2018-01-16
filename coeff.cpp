#include<iostream>
using namespace std;

int main()
{
 const int MAX_N = 10;
 double p0[MAX_N];
 double p1[MAX_N];
 double p2[MAX_N * 2] = {0.0};
 int deg0, deg1;
 cout << "Input the degree of p0: ";
 cin >> deg0;
 cout << "Input " << deg0 + 1 << " coefficient(s) for p0: ";
 for(int i=0; i<= deg0; i++)
 {
 cin >> p0[i];
 }
 cout << "\nInput the degree of p1: ";
 cin >> deg1;
 cout << "Input " << deg1 + 1 << " coefficient(s) for p1: ";
 for(int i=0; i<= deg1; i++)
 {
 cin >> p1[i];
 }

 for (int i=0; i<=deg0; i++)
 {
    for (int j=0; j<=deg1; j++)
    {
       p2[i+j] += p0[i]*p1[j];
    }
}
cout << "\nThe degree of the product p0 x p1 is " << deg0+deg1;
cout << "\nThe coefficients of the product are: ";
for (int i=0; i<=deg0+deg1; i++)
{
   cout << p2[i] << " ";
}
 return 0;
}
