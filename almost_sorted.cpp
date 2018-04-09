#include <bits/stdc++.h>

using namespace std;

void swap(int& a,int& b){
    int temp = a;
    a = b;
    b = temp;
}

int* swap_to_sort(vector<int> arr){
    int len = arr.size();
    int* result = new int[2];
    if (arr[0]>arr[1]){
        result[0] = 0;
    }
    if (arr[len-1]<arr[len-2]){
        result[1] = len-1;
    }
    for (int i=1; i<len-1; i++){
        if (arr[i]>arr[i-1]&&arr[i]>arr[i+1]){
            result[0] = i;
            break;
        }
    }
    for (int i=len-2; i>result[0]; i--){
        if (arr[i]<arr[i-1]&&arr[i]<arr[i+1]){
            result[1] = i;
            break;
        }
    }
    swap(arr[result[0]],arr[result[1]]);
    for (int i=0; i<len-1; i++){
        if (arr[i]>arr[i+1]){
            result[0] = -1;
            result[1] = -1;
            return result;
        }
    }
    return result;
}

int reverse_to_sort(vector<int> arr, int index1){
    int index2 = -1;
    int len = arr.size();
    for (int i=index1+1; i<len-1; i++){
        if (arr[i]<arr[i+1]){
            index2 = i;
            break;
        }
    }
    //cout << "index2 in the middle of function is " << index2 <<endl;
    if (index2==-1) return -1;
    for (int i = index1; i<=(index2+index1)/2; i++){
        swap(arr[i],arr[index2+index1-i]);
    }
    for (int i=0; i<len-1; i++){
        if (arr[i]>arr[i+1]){
            return -1;
        }
    }
    return index2;
}

void almostSorted(vector <int> arr) {
    // Complete this function
    int len = arr.size();
    int index1 = -1;
    int index2 = -1;
    for (int i=0; i<len-1; i++){
        if (arr[i+1]<arr[i]){
            index1 = i;
            break;
        }
    }
    if (index1==-1){
        cout << "yes\n";
        return;
    }
    int* result1 = swap_to_sort(arr);
    if (result1[0]!=-1){
        cout << "yes\n";
        cout << "swap " << result1[0]+1 << " " << result1[1]+1 << endl;
        return;
    }
    index2 = reverse_to_sort(arr,index1);
    //cout << "index1 is " << index1 << "; index2 is " << index2 << endl;
    if (index2!=-1){
        cout << "yes\n";
        cout << "reverse " << index1+1 << " " << index2+1 << endl;
        return;
    }
    cout << "no\n";
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    almostSorted(arr);
    return 0;
}
