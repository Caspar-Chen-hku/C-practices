#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;

int** construct_graph(int n){
    srand(time(NULL));
     int** graph = new int*[n];
     int temp;
     for (int i=0; i<4; i++){
         graph[i] = new int[n];
         graph[i][i] = 1e4;
     }
     for (int i=0; i<4; i++){
        for (int j=i+1; j<4; j++){
             temp = rand()%8 + 1;
             graph[i][j] = temp;
             graph[j][i] = temp;
         }
     }
     return graph;
 }

 void display_graph(int** graph){
     for (int i=0; i<4; i++){
         for (int j=0; j<4; j++){
             cout << graph[i][j] << '\t';
         }
         cout << endl;
     }
 }

   int main()
   {
    int** graph = construct_graph(4);
    display_graph(graph);
    return 0;
    }
