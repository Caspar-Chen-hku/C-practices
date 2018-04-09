#include <iostream>
using namespace std;

bool isEqualPartial(int** initial, int** target, int row, int col){
    for (int i=row; i<row+2; i++){
        for (int j=col; j<col+2; j++){
            if (initial[i][j]!=target[i][j]) return false;
        }
    }
    return true;
}

bool isEqual(int** initial, int** target){
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (initial[i][j]!=target[i][j]) return false;
        }
    }
    return true;
}

void turn(int** initial, int row, int col){
    int temp = initial[row][col];
    initial[row][col] = initial[row+1][col];
    initial[row+1][col] = initial[row+1][col+1];
    initial[row+1][col+1] = initial[row][col+1];
    initial[row][col+1] = temp;
}

int numOp(int** initial, int** target){
    int count = 0;
    bool equal = true;
    int partialCount = 0;
    while (!isEqual(initial,target)){
    for (int i=0; i<2; i++){
        for (int j=0; j<2; j++){
            while(isEqualPartial(initial,target,i,j)==false&&partialCount<3){
                equal = false;
                turn(initial,i,j);
                partialCount++;
            }
            if (!equal){
                count++;
            }
            equal = true;
            partialCount = 0;
        }
    }
    }
    return count;
}

int main(){
    int t;
    cin >> t;
    int** initial;
    int** target;
    string temp;
    for (int i=0; i<t; i++){
        initial = new int*[3];
        target = new int*[3];
        for (int j=0; j<3; j++){
            initial[j] = new int[3];
            target[j] = new int[3];
        }
        for (int j=0; j<3; j++){
            for (int k=0; k<3; k++){
                cin >> initial[j][k];
            }
        }
        for (int j=0; j<3; j++){
            for (int k=0; k<3; k++){
                cin >> target[j][k];
            }
        }
        cout << numOp(initial,target) << endl;
        for (int j=0; j<3; j++){
            delete[] initial[j];
            delete[] target[j];
        }
        delete[] initial;
        delete[] target;
        if (i!=t-1) cin >> temp;
    }
    return 0;
}
