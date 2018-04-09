#include <iostream>
#include <string>
using namespace std;

double averageLen(string s){
    int count = 1;
    double numSeg = 0.0;
    double sum = 0.0;
    for (int i=0; i<s.length()-1; i++){
        if (s[i]==s[i+1]) count++;
        else {
            numSeg+=1.0;
            sum+=count;
            count=1;
        }
    }
    numSeg+=1.0;
    sum+=count;
    cout << "number of seg is: " << numSeg;
    cout <<"sum is: " <<sum;
    return sum/numSeg;
}

int main(){
    string n;
    while (cin>>n){
        cout << averageLen(n) << endl;
    }
    return 0;
}
