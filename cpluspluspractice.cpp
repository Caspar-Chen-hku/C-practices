#include <iostream>
#include <string>
using namespace std;

template <class Some1, int N>

Some1 multiply (Some1 a){
return a*N;}

int main(){
cout << multiply<int,2>(1) << endl;



return 0;}
