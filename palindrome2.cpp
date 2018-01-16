#include <iostream>
using namespace std;

bool charAndNum(char text){
    if ((text>='a' && text<='z') || (text>='A' && text<='Z')
        || (text>='0' && text<='9')){
            return true;
        }
        return false;}
        
string makeFixed (){
    string fixed = "";
    char text;
    while (cin >> text){
        if (charAndNum (text) == true){
            fixed += text;
        }
    }
    return fixed;
}

int main(){
    string fixed = makeFixed();
    int lth = fixed.length();
    for (int i=0; i<lth; i++){
        if (fixed[i]>='A' && fixed[i]<='Z'){
            fixed[i] -= ('A'-'a');
        }
    }
    for (int i=0; i<lth/2; i++){
        if (fixed[i] != fixed[lth-1-i]){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
    }