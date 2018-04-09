#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void removeDuplicate(vector<int>& arr){
    for (int i=0 ;i<arr.size()-1; i++){
        if (arr[i]==arr[i+1]){
            arr.erase(arr.begin()+i);
            i--;
        }
    }
}

int main(){
    vector<int> arr;
    int n;
    while (cin >> n){
    int temp;
    for (int i=0; i<n; i++){
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end());
    //cout << endl << "array size is: " << arr.size() << endl;
    removeDuplicate(arr);
    //cout << "array size is: " << arr.size() <<endl;
    for (int i=0; i<arr.size(); i++){
        cout << arr[i] << endl;
    }
    arr.empty();
    }
    return 0;
}
