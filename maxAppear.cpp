#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <string>
using namespace std;

/*int maxpossible = 100;
int size = 10;


void display(vector<int> target){
    for (int i=0; i<size; i++){
        cout << target[i] << " ";
    }
    cout << endl;
}

void findMinMaxDiff(vector<int> target){
    sort(target.begin(),target.end());
    cout << "sorted target: ";
    display(target);

    cout << "maxdiff is " << target[size-1] - target[0] << endl;

    int mindiff = maxpossible;
    int temp;
    for (int i=0; i<size-1; i++){
        temp = target[i+1]-target[i];
        if (temp<mindiff) mindiff = temp;
    }
    cout << "mindiff is " << mindiff << endl;
}*/

int power2(int n){
    int result = 1;
    for (int i=0; i<n; i++){
        result*=2;
    }
    return result;
}

string* greyCode(int n){
    int len = power2(n);
    string* result = new string[len];
    if (n==1){
        result[0] = "0";
        result[1] = "1";
        return result;
    }
    string* r1 = greyCode(n-1);
    for (int i=0; i<len/2; i++){
        result[i] = "0"+r1[i];
    }
    for (int i=len/2; i<len; i++){
        result[i] = "1"+r1[len-1-i];
    }
    return result;
}

void display_code(string* s, int n){
    int len = power2(n);
    for (int i=0; i<len; i++){
        cout << s[i] << " ";
    }
    cout << endl;
}

int maxAppear(vector<int> arr, int n){
    int maxcount = 1;
    int maxnum;
    int temp = 0;
    sort(arr.begin(),arr.end());
    for (int i=1; i<n; i++){
        if (arr[i]==arr[i-1]){
            temp++;
            continue;
        }
        if (maxcount<temp){
            maxcount=temp;
            maxnum = arr[i-1];
            temp = 0;
        }
    }
    if (maxcount<n/2) return 0;
    return maxnum;
}

int main() {
    /*srand(time(NULL));
    vector<int> target;
    for (int i=0; i<size; i++){
        target.push_back(rand()%100);
    }
    display(target);
    findMinMaxDiff(target);

    display_code(greyCode(4),4);*/

    srand(time(NULL));
    vector<int> arr;
    int n = 100;
    for (int i=0; i<n; i++){
        arr.push_back(rand()%3);
    }
    cout << "maxAppear is " << maxAppear(arr,n) << endl;

	return 0;
}
