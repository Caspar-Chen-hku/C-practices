#include <string>
#include <iostream>
using namespace std;

int possibleCases(string s,int n){
    int index = s.find('X');
    if (index==-1){
        if ((atoi(s.c_str()))%n==0) return 1;
        else return 0;
    }
    string temp = s;
    int result = 0;
    string strnum;
    for (int i=0; i<10; i++){
            strnum = '0' + i;
        s.replace(index,1,strnum);
        result += possibleCases(s,n);
        s = temp;
    }
    return result;
}

int main(){
    string s;
    int n;
    while (cin>>s){
        cin>>n;
        cout << possibleCases(s,n) << endl;
    }
return 0;
}
