#include <iostream>
using namespace std;

int findOnes(int n){
    if (n==0) return 0;
    int count=0;
    while (n>=1){
        count+=n%2;
        n/=2;
    }
    return count;
}

int* seperate_parity(int a[], int size){
    int i=0;
    int j=size-1;
    int* result = new int[size];
    int index=0;
    while (j>=i){
        if (a[index]%2==0){
            result[j]=a[index];
            j--;
        }
        else{
            result[i]=a[index];
            i++;
        }
        index++;
    }
    return result;
}

int main() {
    cout << findOnes(25) << endl;
    
    int a[]={1,3,4,6,7,8,9,5,2};
    
    int* result = seperate_parity(a,9);
    for (int i=0; i<9; i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}