#include <iostream>
using namespace std;

long findMin(int* arr, int n, long sum){
    bool** result = new bool*[n+1];
    for (int i=0; i<=n; i++){
        result[i] = new bool[sum+1];
        result[i][0] = true;
    }
    for (int i=1; i<=sum; i++){
        result[0][i] = false;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=sum; j++){
            result[i][j] = result[i-1][j];
            if (arr[i]<=j&&result[i-1][j-arr[i]]){
                result[i][j]=result[i-1][j-arr[i]];
            }
        }
    }
    int other;
    for (int i=sum/2; i>0; i--){
        if (result[n][i]){
            delete[] result;
            other = sum-i;
            return (other>i?other:i);
        }
    }
    return sum;
}
int main(){
    int n;
    long sum;
    int* arr;
    while(cin>>n){
        arr = new int[n];
        sum=0;
        for (int i=0; i<n; i++){
            cin >> arr[i];
            arr[i]/=1024;
            sum+=arr[i];
        }
        cout << findMin(arr,n,sum)*1024 << endl;
    }
    return 0;
}
