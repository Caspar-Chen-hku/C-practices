#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

long numFirst(int n, int m){
    if (n==1) return m;
    if (m<n) return 0;
    return (m+1)/2;
}

int main(){
    int n;
    cin >> n;

    long* m = new long[n];

    for (int i=0; i<n; i++){
        cin >> m[i];
    }

    sort(m,m+n);

    long result = 0;
    int i;
    for (i=n-1; i>0; i-=2){
        result += (m[i]-m[i-1]);
    }

    if (i==0){
        result += m[0];
    }

    cout << result << endl;

    return 0;
}
