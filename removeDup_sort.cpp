#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    map<int,int> arr;
    int n;
    while (cin >> n){
    int temp;
    for (int i=0; i<n; i++){
        cin >> temp;
        arr[temp] = i;
    }
    for (map<int,int>::iterator i=arr.begin(); i!=arr.end(); i++){
        cout << (*i).first <<endl;
    }
    arr.empty();
    }
    return 0;
}
