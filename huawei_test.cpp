#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> toVec(string s){
    vector<int> result;
    for (int i=s.length()-1; i>=0; i--){
        result.push_back( s[i]-'0' );
    }
    return result;
}

vector<int> add(vector<int>& a,vector<int>& b){
    if (a.empty()) return b;
    vector<int> result;
    int len = (a.size()>b.size()?b.size():a.size());
    int carry = 0;
    int temp;
    for (int i=0; i<len; i++){
        temp = a[i] + b[i] + carry;
        carry = 0;
        if (temp>=10) {
            temp %= 10;
            carry = 1;
        }
        result.push_back(temp);
    }
    if (a.size()>len){
        result.push_back(a[len]+carry);
    } else if (b.size()>len) {
        result.push_back(b[len]+carry);
    } else if (carry==1){
        result.push_back(1);
    }
    return result;
}

vector<int> multiply_int(vector<int>& a,int b){
    vector<int> result;
    int carry = 0;
    int temp;
    for (int i=0; i<a.size(); i++){
        temp = a[i]*b + carry;
        carry = temp/10;
        temp %= 10;
        result.push_back(temp);
    }
    if (carry>0){
        result.push_back(carry);
    }
    return result;
}

vector<int> multiply(vector<int>& a,vector<int>& b){
    vector<int> result;
    vector<int> temp;
    int index;
    for (int i=0; i<b.size(); i++){
        temp = multiply_int(a,b[i]);
        index=i;
        while (index>0){
            temp.insert(temp.begin(),0);
            index--;
        }
        result = add(result,temp);
    }
    return result;
}

int main(){
    string s1;
    string s2;
    cin >> s1 >> s2;
    int sign = 0;
    if (s1[0]=='-'){
        sign++;
        s1 = s1.substr(1);
    }
    if (s2[0]=='-'){
        sign++;
        s2 = s2.substr(1);
    }
    sign %= 2;
    vector<int> a1 = toVec(s1);
    vector<int> a2 = toVec(s2);
    vector<int> result = multiply(a1,a2);

    if (sign==1) cout << "-";
    for (int i=result.size()-1; i>=0; i--){
        cout << result[i];
    }
    cout << endl;
    return 0;
}
