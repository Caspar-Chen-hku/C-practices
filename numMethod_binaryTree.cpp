#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int* arr = new int[n+1]();
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    for (int i=3; i<=n; i++){
        for (int j=0; j<=i-1; j++){
            arr[i] += (arr[j]*arr[i-1-j]);
        }
    }
    for (int i=1; i<=n; i++){
        cout << i << ':' << arr[i] << endl;
    }
    delete[] arr;
    return 0;
}
