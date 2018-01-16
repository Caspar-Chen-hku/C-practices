#include <iostream>
#include <cmath>
using namespace std;

int max(int x1,int x2,int y1,int y2){
    if  (abs(x1-x2)>=abs(y1-y2))
      return abs(x1-x2);
    else
      return abs(y1-y2);}
      
int main(){
    int x[100];
    int y[100];
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> x[i] >> y[i];
    }
    int dis = max(x[0],x[1],y[0],y[1]);
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (max(x[i],x[j],y[i],y[j])<dis)
            dis = max(x[i],x[j],y[i],y[j]);
        }
    }
    cout << dis*dis;
    return 0;}