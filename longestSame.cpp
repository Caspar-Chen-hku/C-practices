#include <iostream>
#include <string>
using namespace std;

int maxRegion(string* chess, int n){
    int max = 1;
    int temp=1;
    for (int j=0; j<n; j++){
        for (int i=0; i<n-1; i++){
            if (chess[i][j]==chess[i+1][j]){
                temp++;
                if (temp>max) {
                        max=temp;
                }
            }else{
                temp = 1;
            }
        }
        temp = 1;
    }
    return max;
}

int main(){
    string* chess;
    int n;
    while(cin>>n){
        chess = new string[n];
        for (int i=0; i<n; i++){
            cin >> chess[i];
        }
        cout << maxRegion(chess,n) << endl;
        delete[] chess;
    }
    return 0;
}
