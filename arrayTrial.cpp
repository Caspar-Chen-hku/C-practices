#include <iostream>
#include <array>
using namespace std;

struct A{
int a;
short b;
int c;
char d;};

int main(){
int a[2][2]={{1},{2}};
cout << a.size() << endl;
cout << a[0].size() << endl;
cout << a[1].size() << endl;
return 0;
}
