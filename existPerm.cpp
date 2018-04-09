#include <iostream>
#include <vector>
using namespace std;

vector<int> result;

bool canFind(vector<int>& v){
    if (result.empty()){
        result.push_back(v[0]);
        v.erase(v.begin());
        return canFind(v);
    }else if(v.empty()){
        return true;
    }
    int vSize = v.size();
    for (int i=0; i<=result.size(); i++){
            for (int j=0; j<vSize; j++){
        if (i==0){
            if ((v[j]*result[0])%4==0){
                result.insert(result.begin(),v[j]);
                v.erase(v.begin()+j);
                return canFind(v);
            }
        }
        else if (i<result.size()){
            if ((v[j]*result[i-1])%4==0 && (v[j]*result[i])%4==0){
                result.insert(result.begin()+i,v[j]);
                v.erase(v.begin()+j);
                return canFind(v);
            }
        }
        else {
            if ((v[j]*result[i-1])%4==0){
                result.insert(result.begin()+i,v[j]);
                v.erase(v.begin()+j);
                return canFind(v);
            }
        }
    }
    }
    return false;
}
int main(){
    int n,m,temp;
    vector<int> v;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> m;
        for (int i=0; i<m; i++){
            cin >> temp;
            v.push_back(temp);
        }
        if (canFind(v)) cout << "Yes" << endl;
        else cout << "No" << endl;
        v.clear();
        result.clear();
    }
    return 0;
}
