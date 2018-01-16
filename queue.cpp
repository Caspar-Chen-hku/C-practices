#include<iostream>
using namespace std;

void showQueueFrom(int next[], int userID);
bool isTail(int next[], int userID, int n);


int main(){
    int n;
    cin >> n;
    int *next = new int[n];

    for (int i=0 ; i < n ; i++){
        cin >> next[i];
    }

    int isTailInput;
    cin >> isTailInput;
    if (isTail(next,isTailInput,n) == true)
        cout << isTailInput << " is Tail." << endl;
    else
        cout << isTailInput << " is not Tail." << endl;



    int showQueueFromInput;
    cin >> showQueueFromInput;
    showQueueFrom(next,showQueueFromInput);
}

bool isTail(int next[], int userID, int n){
    for (int i=0; i<n; i++){
        if (next[i]==userID) return false;
    }
    return true;
}

void showQueueFrom(int next[], int userID){
    int index=userID;
    while(index!=-1){
        cout << index << " ";
        index=next[index];
    }
}