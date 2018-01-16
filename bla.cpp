#include<iostream>
using namespace std;
int main()
{
 const int MAX_N = 10;
 double p0[MAX_N];
 double p1[MAX_N];
 double p2[MAX_N * 2] = {};
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

 int i=0;
 for ( i=0; i <= deg0 + deg1; i++)
 {
    if (i <= deg1)
    {
        int i1=0, i2=i;
        for (i2=i; i2 >= 0; i2--)
    {
        if (i1 <= deg0)
        {
            p2[i] += p0[i1]*p1[i2];
            i1++;
        }

    }
    }

    if (i > deg1 )
    {
        int i2=deg1, i1=i-deg1;
        for (i2=deg1; i2 >= 0&&i1 <= deg0; i2--)
        {
             p2[i] += p0[i1]*p1[i2];
            i1++;
        }
    }
}
i--;

cout << "The degree of the product p0 x p1 is " << i << endl;
cout << "The coefficients of the product are: ";

for ( int counter=0; counter <= i; counter++)
{
    cout << p2[counter] << " ";
}

 return 0;
}
