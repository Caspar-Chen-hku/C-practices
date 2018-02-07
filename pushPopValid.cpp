#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool valid (vector<int>& arr_push, vector<int>& arr_pop){
    
    int size1 = arr_push.size();
    int size2 = arr_pop.size();
    cout << size1 << " " << size2 << endl;
    
    stack<int> s;
    int index_push=0;
    int index_pop=0;
    bool empty = false;
    while(index_push<size1 && !empty){
        s.push(arr_push[index_push]);
        while(s.top()==arr_pop[index_pop] && !empty){
            s.pop();
            index_pop++;
            arr_push.erase(arr_push.begin()+index_push);
            index_push--;
            if (s.empty()) empty=true;
        }
        index_push++;
    }
    return empty;
}

int main() {
    int arr_push[] = {1,2,3,4,5};
    int arr_pop[] = {4,5,3,2,1};
    
    vector<int> vec_push (arr_push, arr_push + 5);
    vector<int> vec_pop (arr_pop, arr_pop + 5);
    if (valid(vec_push,vec_pop)) {
        cout << "1: valid!" << endl;
    }
    else cout << "1: invalid!" << endl;
    
    int arr1[] = {4,3,5,1,2};
    vector<int> push1(arr_push, arr_push + 5);
    vector<int> pop1(arr1, arr1 + 5);
    
    if (!valid(push1,pop1)) {
        cout << "2: invalid!" << endl;
    }
    else cout << "2: valid!" << endl;
    
    return 0;
}