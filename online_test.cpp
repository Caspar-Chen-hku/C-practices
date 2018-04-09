#include <iostream>
#include <vector>
using namespace std;

vector<long>::iterator find(vector<long>& arr, long target){
    for (int i=0; i<arr.size(); i++){
        if (arr[i]==target) return arr.begin()+i;
    }
    return arr.end();
}

int main(){
    int t,n;
    long temp;
    vector<long>::iterator it;
    vector<long> arr;
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> n;
        for (int j=0; j<n; j++){
            cin >> temp;
            it = find(arr,temp);
            if(it!=arr.end()){
                arr.erase(it);
            }
            arr.insert(arr.begin(),temp);
        }
        for (int j=0; j<arr.size(); j++){
            cout << arr[j];
            if (j==arr.size()-1){
                cout << endl;
            }else{
                cout << ' ';
            }
        }
        arr.clear();
    }
    return 0;
}
