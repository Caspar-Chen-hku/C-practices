#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int n = 5;
int m = 6;

int clean(int** war_map){
    int maxcount = 0;
    int maxi;
    int maxj;
    int temp=0;
   for (int i=0; i<n-2; i++){
       for (int j=0; j<m-2; j++){
           temp=0;
           for (int k=i; k<=i+2; k++){
               for (int l=j; l<=j+2; l++){
                   temp+=war_map[k][l];
               }
           }
           if (temp>maxcount){
               maxcount = temp;
               maxi = i;
               maxj = j;
           }
       }
   }
   for (int i=maxi; i<=maxi+2; i++){
       for (int j=maxj; j<=maxj+2; j++){
           if (war_map[i][j]==0) continue;
           war_map[i][j]--;
       }
   }
   return maxcount;
}

void display_map(int** war_map){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << war_map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    srand(time(NULL));
    int** war_map = new int*[n];
    for (int i=0; i<n; i++){
        war_map[i] = new int[m];
        for (int j=0; j<m; j++){
            war_map[i][j] = rand()%3;
        }
    }
    cout << "The map looks like:\n";
    display_map(war_map);

    cout << "The first time we cleaned " << clean(war_map) << " bombs\n";
    cout << "The map now looks like:\n";
    display_map(war_map);

    cout << "The second time we cleaned " << clean(war_map) << " bombs\n";
    cout << "The map now looks like:\n";
    display_map(war_map);

	return 0;
}
