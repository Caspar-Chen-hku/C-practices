//calculate the check digit

#include <iostream>
using namespace std;

int main()
{
    int csc;
    cout<<"Enter CSC:";
    cin>>csc;

    int g=csc%10;

    int s=csc%100;
    int sh=s-g;
    int shi=sh/10;

    int b=csc-s;
    int ba=b/100;

    int d=g*3+shi+ba*3;
    int rd=d%10;
    int cd=10-rd;

    cout<<"Check digit is:"<<cd;
    return 0;
}
