#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool whether(int n, long m, long current){
    long result = 0;
    for (int i=0; i<n; i++){
        result += current;
        if (result>m) return false;
        current = (long) ceil(1.0*current/2);
    }
    return true;
}

long numFirst(int n, long m){
    if (n==1) return m;
    if (m==n) return 1;
    if (n>16||m>pow(2,n)){
            cout << "entered1" << endl;
      for (long i=(m+1)/2; i>0; i--){
        if(whether(n,m,i)) return i;
      }
    }else{
        cout << "entered2" <<endl;
      for (long i=pow(2,n-1); i>0; i--){
        if(whether(n,m,i)) return i;
      }
    }

    return 0;
}

int main(){
    int n;
    long m;
    cin >> n >> m;

    cout << numFirst(n,m) << endl;
    return 0;
}
