#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int maxCrazy(vector<int> arr, int n){
    int increment = 0;
    vector<int> result;
    sort(arr.begin(),arr.end());
    result.push_back(arr[n-1]);
    arr.erase(arr.begin()+n-1);
    bool small = true;
    int len;
    while (!arr.empty()){
            len = arr.size();
        if (small){
            result.push_back(arr[0]);
            arr.erase(arr.begin());
            if (arr.empty()) break;
            result.insert(result.begin(),arr[0]);
            arr.erase(arr.begin());
            if (arr.empty()) break;
        }
        else{
            result.push_back(arr[len-1]);
            arr.erase(arr.begin()+len-1);
            if (arr.empty()) break;
            result.insert(result.begin(),arr[len-1]);
            arr.erase(arr.begin()+len-1);
            if (arr.empty()) break;
        }
        small = !small;
    }
    int crazy = 0;
    for (int i=0; i<n-1; i++){
        crazy += abs(result[i]-result[i+1]);
    }
    return crazy;
}

int main(){
    int n,temp;
    vector<int> arr;
    while(cin>>n){
        for (int i=0; i<n; i++){
            cin >> temp;
            arr.push_back(temp);
        }
        cout << maxCrazy(arr,n) << endl;
        for (int i=0; i<n; i++){
            cout << arr[i] << ' ';
        }
        arr.clear();
    }
    return 0;
}
