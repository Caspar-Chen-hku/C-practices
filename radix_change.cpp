#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int m;
char convert[]="0123456789abcdefghij";

int* newNum(int a, int radix){
    int* arr = new int[12];
    m = 0;
    while (a>0){
        arr[m] = a%radix;
        a /= radix;
        m++;
    }
    return arr;
}

int newNumReverse(int* arr, int radix, int m){
    int result = 0;
    for (int i=0; i<m; i++){
        result += arr[i]*pow(radix,i);
    }
    return result;
}

void display_num(int* arr, int m){
    for (int i=m-1; i>=0; i--){
        cout << convert[arr[i]];
    }
    cout << endl;
}

int main(){

    int n,radix;
    int* result;
    string instruction;
    string temp;
    while (cin>>instruction){
        if (instruction=="todecimal"){
            cin >> temp >>radix;
            m = temp.length();
            result = new int[m];
            for (int i=0; i<m; i++){
                result[i] = temp[m-1-i]-'0';
            }
            cout << newNumReverse(result,radix,m) <<endl;
        }
        else if (instruction=="fromdecimal"){
            cin >> n >> radix;
            result = newNum(n,radix);
            display_num(result,m);
        } else break;
    }
    return 0;
}
