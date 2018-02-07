#include <iostream>
#include <string>
#include <set>
using namespace std;

bool isCircular(string a){
    int len = a.length();
    if (len==0||len==1) return true;
    int i=0;
    int j=len-1;
    while (j>i){
        if (a[i]!=a[j]) return false;
        j--;
        i++;
    }
    return true;
}

set<int> find_union(int a1[],int size1, int a2[], int size2){
    set<int> result;
    for (int i=0; i<size1; i++){
        if (result.count(a1[i])==0){
            result.insert(a1[i]);
        }
    }
    for (int i=0; i<size2; i++){
        if (result.count(a2[i])==0){
            result.insert(a2[i]);
        }
    }
    return result;
}

set<int> find_intercept(int a1[], int size1, int a2[], int size2){
    set<int> set2 (a2, a2+size2);
    set<int> result;
    for (int i=0; i<size1; i++){
        if (set2.count(a1[i])>0) result.insert(a1[i]);
    }
    return result;
}

int main() {
    //if (isCircular("watashi")) cout << "yes" << endl;
    //else cout << "no" << endl;
    //if (isCircular("abcdedcba")) cout << "yes" << endl;
    //else cout << "no" << endl;
    
   
    int a1[]={1,4,6,8,7,5};
    int a2[]={3,6,9,8,7};
    
    set<int> s_union=find_union(a1,6,a2,5);
    for (auto i=s_union.begin(); i!=s_union.end(); i++){
        cout << *i << " ";
    }
    cout << endl;
    
    set<int> s_intercept = find_intercept(a1,6,a2,5);
    for (auto i=s_intercept.begin(); i!=s_intercept.end(); i++){
        cout << *i << " ";
    }
    cout << endl;
    
    return 0;
}