#include <iostream>
#include <string>
using namespace std;

bool isUniq(string x){
    for (int i=0; i<x.length()-1; i++){
        if (x[i]==x[i+1]) return false;
    }
    return true;}

int main(){
    string x;
    cin >> x;
    while(!isUniq(x)){
        for (int i=0; i<x.length()-1; i++){
            if (x[i]==x[i+1]) {x.erase(i,2);
            i--;}
        }
    }
    cout <<x;
}