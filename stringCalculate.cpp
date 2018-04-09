#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int findDividingPoint(string s){
    if (s.length()<=2) return -1;
    int max = 0;
    int index = 1;
    int temp;
    for (int i=1; i<s.length()-1; i++){
        if (s[i]!='|'&&s[i]!='&') continue;
        temp = 0;
        for (int j=i-1; j>0; j--){
            if (s[j]==')') temp++;
            else break;
        }
        for (int j=i+1; j<s.length()-1; j++){
            if (s[j]=='(') temp++;
            else break;
        }
        if (temp>max){
            max = temp;
            index = i;
        }
    }
    return index;
}

int value(string s){
    if (s[0]!='('){
        return atoi(s.c_str());
    }
    int temp;
    string s1,s2;
    s = s.substr(1,s.length()-2);
    int index = findDividingPoint(s);
    if (index==-1){
        temp = atoi(s.substr(1).c_str());
        return !temp;
    }
    s1 = s.substr(0,index);
    s2 = s.substr(index+1);
    if (s[index]=='|'){
        return (value(s1)|value(s2));
    }else{
        return (value(s1)&value(s2));
    }
}

int main(){
    int t;
    string s;
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> s;
        cout << value(s) << endl;
    }
    return 0;
}
