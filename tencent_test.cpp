#include <iostream>
#include <string>
using namespace std;

bool match1(int** matrix, int i, int j, int len){
    char tomatch = matrix[i][j];
    if (tomatch=='X') return false;
    for (int index=1; index<len; index++){
        if (matrix[i+index][j+index]!=tomatch&&matrix[i+index][j+index]!='G'){
            return false;
        }
    }
     matrix[i][j] = 'X';
     for (int index=1; index<len; index++){
        if (matrix[i+index][j+index]=='G'){
            if (tomatch=='B') matrix[i+index][j+index]='Y';
            else matrix[i+index][j+index]='B';
        }else{
            matrix[i+index][j+index]='X';
        }
    }
        return true;
}

bool match2(int** matrix, int i, int j, int len){
    char tomatch = matrix[i][j];
    if (tomatch=='X') return false;
    for (int index=1; index<len; index++){
        if (matrix[i+index][j-index]!=tomatch&&matrix[i+index][j-index]!='G'){
            return false;
        }
    }

    matrix[i][j] = 'X';
     for (int index=1; index<len; index++){
        if (matrix[i+index][j-index]=='G'){
            if (tomatch=='B') matrix[i+index][j-index]='Y';
            else matrix[i+index][j-index]='B';
        }else{
            matrix[i+index][j-index]='X';
        }
    }
    return true;
}

int* longest(int** matrix, int m, int n){
    int* result = new int[3]();
    int maxLen = (m>n?n:m);

    int j;
    for (int k=maxLen; k>0; k--){
        for (int i=0; i<=n-k; i++){
          for (int j=0; j<=m-k; j++){
            if (match1(matrix,i,j,k)){
                result[0]=i;
                result[1]=j;
                result[2]=k;
                return result;
            }
          }
          for (int j=k-1; j<m; j++){
            if (match2(matrix,i,j,k)){
                result[0]=i;
                result[1]=j;
                result[2]=k;
                return result;
            }
          }
        }
    }
    result[2] = 0;
    return result;
}

int numOp(int** matrix, int m, int n){
    int* temp;
    int counter = 0;
    temp = longest(matrix,m,n);
    while (temp[2]!=0){
        cout << temp[0] << ' ' << temp[1] << ' ' << temp[2] << " \n";
        counter++;
        temp = longest(matrix,m,n);
    }
    return counter;
}

int main(){
    int n,m;
    cin >> n >> m;
    string s;

    int** matrix = new int*[n];
    for (int i=0; i<n; i++){
        matrix[i] = new int[m];
        cin >> s;
        for (int j=0; j<m; j++){
            matrix[i][j] = s[j];
        }
    }
    cout << numOp(matrix,m,n) << endl;
    return 0;
}
