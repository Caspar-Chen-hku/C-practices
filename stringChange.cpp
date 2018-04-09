#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string change(string s){
    string result = "";
    char* temp;
    int count = 1;
    for (int i=0; i<s.length()-1; i++){
        if (s[i]==s[i+1]) count++;
        else{
            itoa(count,temp,10);
            result += temp + s.substr(i,1);
            count = 1;
        }
    }
    return result;
}

int main(){
    string s;
    cin >> s;
    cout << change(s) << endl;
    return 0;
}
