#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int findIndex(string s, int n){
    int r1 = (s[0]-'a')*n/25;
    cout << "r1 is " << r1 << endl;
    if (s.length()==1) return r1;
    string temp = s.substr(1);
    return r1 + 1 + findIndex(temp,n/25);
}

bool isPrime(int n){
    for (int i=2; i<sqrt(n); i++){
        if (n%i==0) return false;
    }
    return true;
}
int numOfPrimePair(int n){
    int num=0;
    for (int i=2; i<=n/2; i++){
        if (isPrime(i)&&isPrime(n-i)){
            num++;
            cout << "(" << i << "," << n-i << ")\n";
        }
    }
    return num;
}

string geomode(int n,int low,int high){
    if (high-low<6) return "";
    int divider = (low+high)/2;
    if (n<divider){
        return "0"+geomode(n,low,divider);
    }
    return "1"+geomode(n,divider,high);
}

   int main()
   {
    int n = 25 + pow(25,2) + pow(25,3) + pow(25,4);
    cout << "n is " << n << endl;
    cout << "index of abcd is " << findIndex("abcd",n) << endl;

    cout << "number of prime pairs is " << numOfPrimePair(100) << endl;

    cout << "geomode of 75 is " << geomode(75, -90, 90) << endl;
    return 0;
    }
