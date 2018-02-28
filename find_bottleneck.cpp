#include <iostream>
#include <time.h>
#include <cstdlib>
#include <math.h>
using namespace std;

int n = 64;
int k = 16;

int find_smallest_k(int* arr, int h){
    if (h<n) return n+1;
    int sum = 0;
    int count = 0;
    for (int i=0; i<n; i++){
        sum+=arr[i];
        if (sum>h){
            sum=arr[i];
            count++;
        }
    }
    return count;
}

int find_bottleneck(int* arr, int low, int high){
    if (low==high) return low;
    int mid = (low+high)/2;
    int num = find_smallest_k(arr,mid);
    cout << "num now is " << num << endl;
    if (num > k){
        return find_bottleneck(arr, mid+1, high);
    }
    return find_bottleneck(arr, low, mid);
}

int* find_arr(){
    srand(time(NULL));
    int* arr = new int[n];
    for (int i=0; i<n; i++){
        arr[i] = rand()%n;
    }
    return arr;
}

void display(int* arr){
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
        if ((i+1)%4==0) cout << endl;
    }
}

int find_sum(int* arr){
    int sum=0;
    for (int i=0; i<n; i++){
        sum+=arr[i];
    }
    return sum;
}

int main() {
    int* arr = find_arr();
    display(arr);

    cout << "Bottleneck is " << find_bottleneck(arr,arr[0],find_sum(arr)) << endl;
	return 0;
}
