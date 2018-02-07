#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

//this function can find the number of trailing zeros
//for the result of factorial m
int numOfZeros(int m){
    int count=0;
    int temp;
    for (int i=5; i<=m; i++){
        if (i%5==0){
            temp=i;
            while (temp>5){
                temp/=5;
                count++;
            }
        }
    }
    return count;
}


 
   int main()
   {
    cout << numOfZeros(120) << endl;
    
    //insert 1-100 in random order in an array
    int arr[100];
    vector<int> ints;
    for (int i=1; i<=100; i++){
        ints.push_back(i);
    }
    srand(time(NULL));
    int index=100;
    int current;
   for (int i=0; i<100; i++){
       current=rand()%index;
       arr[i]=ints[current];
       ints.erase(ints.begin()+current);
       index--;
   }
   for (int i=0; i<100; i++){
       cout << arr[i] << " ";
   }
   cout << endl;
    
    return 0;
    }