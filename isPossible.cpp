#include <iostream>
#include <algorithm>
using namespace std;

void isPossible(int* arr, int n){
    int diff = arr[0]-arr[1];
    for (int i=1; i<n-1; i++){
        if (arr[i]-arr[i+1]!=diff){
            cout << "Impossible\n";
            return;
        }
    }
    cout << "Possible\n";
}

int main(){
    int n;
    int* arr;
    while(cin>>n){
        arr = new int[n];
        for (int i=0; i<n; i++){
            cin >> arr[i];
        }
        sort(arr,arr+n);
        isPossible(arr,n);
        delete[] arr;
    }
    return 0;
}
