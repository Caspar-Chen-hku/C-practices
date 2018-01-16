#include<iostream>
using namespace std;

bool is_palindrome(int input[], int numOfSlots);

int main(){
    int n;
    cin >> n;
    int *input = new int[n]; // A dynamic array with n slots
    for (int i = 0 ; i < n ; i++){
        cin >> input[i];
    }

    if (is_palindrome(input,n) == true ){
        cout << "This is a palindrome.";
    }else{
        cout << "This is NOT a palindrome.";
    }
    return 0;
}

bool is_palindrome(int input[], int numOfSlots){
    int count = numOfSlots/2;
    for (int i=0; i<count; i++){
        if (input[i]!=input[numOfSlots-1-i]){
            return false;
        }
    }
    return true;
}