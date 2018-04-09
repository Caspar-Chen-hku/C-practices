#include <iostream>
#include <string>
using namespace std;

int main(){
    int odd[9];
    int even[9];
    odd[2] = 1;
    even[2] = 1;
    for (int i=3; i<9; i++){
        odd[i] = even[i-1];
        even[i] = odd[i-1] + even[i-1];
    }
    cout << odd[8] + even[8] <<endl;
    return 0;
}

