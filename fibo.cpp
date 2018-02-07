#include <iostream>
using namespace std;

int fibo_recursive(int n){
    if (n==1||n==2) return 1;
    return fibo_recursive(n-1)+fibo_recursive(n-2);
}

int fibo_iterative(int n){
    int* arr = new int[n];
    arr[0]=1;
    arr[1]=1;
    if (n==1||n==2) return 1;
    for (int i=2; i<n; i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    return arr[n-1];
}

int main() {
    cout << fibo_recursive(10) << endl;
    cout << fibo_iterative(10) << endl;
    
    return 0;
}