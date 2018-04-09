#include <iostream>
using namespace std;

int sumDepends(int a,int radix){
    int m=0,c;
    int s[20];
    //cout << "a: " << a;
    while(a>0){
        c = a%radix;
        a /= radix;
        m++;s[m]=c;
    }
    int result = 0;
    for (int i=1; i<=m; i++){
        result += s[i];
    }
    //cout << "; radix: " << radix << "; result: " << result << endl;
    return result;
}

int main(){
    int n;
    int counter;
    while(cin>>n){
        counter = 0;
        for (int i=n; i>0; i--){
            if (sumDepends(i,10)==sumDepends(i,2)){
                counter++;
            }
        }
        cout << counter << endl;
    }
    return 0;
}
