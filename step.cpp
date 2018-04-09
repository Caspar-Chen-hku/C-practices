#include <iostream>
using namespace std;

int step(int n,int m){
    int* arr = new int[m-n+1];
    arr[m-n] = 0;
    for (int i=0; i<m-n; i++){
        arr[i] = 10000;
    }
    for (int i=m-n-1; i>=0; i--){
        for (int j=m-n; j>i+1; j--){
            if ((i+n)!=(j-i)&&(i+n)%(j-i)==0&&arr[j]<10000){
                arr[i] = arr[j] + 1;
                //cout << "step now: " << i+n << "to" << j+n << endl;
                break;
            }
        }
    }
    if (arr[0]==10000){
        return -1;
    }else return arr[0];
}

int main(){
    int n,m;
    while (cin>>n){
        cin >> m;
        cout << step(n,m) << endl;
    }
}
