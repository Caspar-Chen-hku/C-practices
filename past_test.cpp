#include <iostream>
#include <string>
using namespace std;

int minToDelete(string s){
    int len = s.length();
    if (len<3){
        return 0;
    }
    else if (s[0]==s[len-1]){
        string subs = s.substr(1,len-2);
        return minToDelete(subs);
    }
    int n1 = minToDelete(s.substr(1));
    int n2 = minToDelete(s.substr(0,len-1));
    return ((n1>n2?n2:n1) + 1);
}
int main(){
    string s;
    while (cin>>s){
        cout << minToDelete(s) << endl;
    }

return 0;
}
