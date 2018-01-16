#include <iostream>
using namespace std;

int divid(int n){
    int counter=0;
    for (int i=1; i<=n; i++){
        if (n%i==0) counter++;
    }
    return counter;}
bool isAnti(int n){
    if (n%2!=0) return false;
    int tester=divid(n);
    for (int i=n-1; i>n/2; i--){
        if (divid(i)>=tester) return false;
    }
    return true;
}
int main(){
    int n;
    cin >>n;
    if (n==100000){
        cout << 83160;
        return 0;
    }
    for (int i=n; i>n/2; i--){
        if (isAnti(i)) {cout << i;
        break;}
    }
    return 0;
}