#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int m,n;
    cin >> m >> n;
    int points[10][2];
    for (int i=0; i<n; i++){
        cin >> points[i][0] >> points[i][1];
    }
     bool chess[100][100];
    for (int i=0; i<m; i++){
        for  (int j=0; j<m; j++){
            chess[i][j]=false; 
        }
    }
    for (int i=0; i<n; i++){
        for (int x=1; x<m+1; x++){
            for (int y=1; y<m+1; y++){
                if ((abs(x-points[i][0])==abs(y-points[i][1])) || 
                (x-points[i][0]==0) || 
                (y-points[i][1]==0))
                chess[x-1][y-1]=true;
            }
        }
    }
    int counter=0;
   for (int i=0; i<m; i++){
       for (int j=0; j<m; j++){
           if (!chess[i][j])
           counter++;
       }
   }
  cout << counter;
  return 0;}