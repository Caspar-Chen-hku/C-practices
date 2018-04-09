#include <iostream>
#include <algorithm>
using namespace std;

void swap(int& a,int& b){
    int temp = a;
    a= b;
    b = temp;
}

int maxCrazy(int* arr, int n){
    int increment = 0;
    while (true){
        if (abs(arr[1]-arr[2])<abs(arr[0]-arr[2])){
            swap(arr[0],arr[1]);
            increment++;
        }
        for (int i=1; i<n-2; i++){
            if (abs(arr[i+2]-arr[i+1]) + abs(arr[i]-arr[i-1]) < abs(arr[i+2]-arr[i]) + abs(arr[i+1]-arr[i-1])){
                swap(arr[i],arr[i+1]);
                increment++;
            }
        }
        if (abs(arr[n-2]-arr[n-3])<abs(arr[n-1]-arr[n-3])){
            swap(arr[n-2],arr[n-1]);
            increment++;
        }
        if (increment==0){
            break;
        }
        increment=0;
    }
    int crazy = 0;
    for (int i=0; i<n-1; i++){
        crazy += abs(arr[i]-arr[i+1]);
    }
    return crazy;
}

int main(){
    int n;
    int* arr;
    while(cin>>n){
        arr = new int[n];
        for (int i=0; i<n; i++){
            cin >> arr[i];
        }
        cout << maxCrazy(arr,n) << endl;
        for (int i=0; i<n; i++){
            cout << arr[i] << ' ';
        }
        delete[] arr;
    }
    return 0;
}
