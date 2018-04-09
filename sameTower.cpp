#include <iostream>
using namespace std;

bool canBuild(int* arr, int target, int start, int end){
    int n = end-start+1;
    bool** tower = new bool*[n+1];
    for (int i=0; i<=n; i++){
        tower[i] = new bool[target+1];
        tower[i][0] = true;
    }
    for (int i=1; i<=target; i++){
        tower[0][i] = false;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=target; j++){
            tower[i][j] = tower[i-1][j];
            if (arr[i-1+start]<=j && tower[i-1][j-arr[i-1+start]]){
                tower[i][j] = true;
            }
        }
    }
    bool result = tower[n][target];
    delete[] tower;
    return result;
}

int maxHeight(int* arr, int n, int halfSum){
   for (int target=halfSum; target>0; target--){
    for (int i=0; i<n-1; i++){
        if (canBuild(arr,target,0,i)&&canBuild(arr,target,i+1,n-1)){
            return target;
        }
    }
   }
   return -1;
}

int main(){
    int n,sum;
    int* arr;
    while (cin >> n){
        arr = new int[n];
        sum = 0;
        for (int i=0; i<n; i++){
            cin >> arr[i];
            sum += arr[i];
        }
        cout << maxHeight(arr,n,sum/2) << endl;
        delete[] arr;
    }
    return 0;
}
