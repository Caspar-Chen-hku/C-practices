//smallest bottleneck
#import <iostream>
using namespace std;

int n;
int k;

int bottleneck(int X[], int B[]){
   /*If (n<=k): B[1]+=X[n];
B[2]+=X[n-1];
��
B[n]+=X[1];
sort B, return B[k]

      else: B[1]+=X[n];
B[2]+=X[n-1];
��
B[k]+=X[n+1-k];
           sort B, return smallest_bottleneck (X[1��n-k], k, B[1��k])*/


}

int main(){
    cin >> n;
    int* X = new int[n];
    for (int i=0; i<n; i++){
        cin >> X[i];
    }


return 0;
}
