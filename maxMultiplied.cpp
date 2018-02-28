#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

int n = 10;

int maxMultiplied(int* arr, int k, int d){
    if (k==1) return arr[n-1];
    int multiplied = 1;
    int count = 2;
    int index=-1;
    for (int i=n-1; i>0; i--){
        if (arr[i]-arr[i-1]<d){
            multiplied = arr[i]*arr[i-1];
            index = i-1;
            break;
        }
    }
    if (index<=0) return index;

    int prev = index;
    for (int i=index-1; i>=0&&count<k; i--){
        if (arr[prev]-arr[i]<d){
            multiplied*=arr[i];
            count++;
            prev=i;
        }
    }
    if (count!=k){
        cout << "No such array found" << endl;
        return -1;
    }
    return multiplied;
}

int* create(){
    srand(time(NULL));
    int* arr = new int[n];
    int prev = 0;
    for (int i=0; i<n; i++){
        arr[i]=rand()%5 + prev;
        prev = arr[i];
    }
    return arr;
}

void display(int* arr){
    for (int i=0; i<n; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
}

    int main()
   {
       int* arr = create();
       display(arr);

       int d = rand()%8 + 2;
       cout << "d is " << d <<endl;
       cout << "The maxMultiplied is: " << maxMultiplied(arr,4,d) << endl;

    return 0;
    }
