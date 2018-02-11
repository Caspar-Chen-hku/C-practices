#include <iostream>
#include <stack>
#include <unordered_set>
#include <time.h>
#include <stdlib.h>
using namespace std;

stack<int> s;

int find_max_sum(int a[],int size){
    int max_sum=0;
    int total_sum=0;
    for (int i=0; i<size; i++){
        total_sum+=a[i];
        if (total_sum<0){
            total_sum=0;
        }
        else if(total_sum>max_sum){
            max_sum=total_sum;
            s.push(i);
        }
    }
    cout << "maximum sum is " << max_sum << endl;
    return max_sum;
}

int* find_interval(int a[],int size){
    int sum = find_max_sum(a,size);
    int j = s.top();
    cout << "j is " << j << endl;
    int temp=0;
    int* result = new int[2];
    for (int i=j; i>=0; i--){
        temp+=a[i];
        if (temp==sum){
            result[0]=i;
            result[1]=j;
            return result;
        }
    }
}

void display(unordered_set<int> a){
    for (auto i=a.begin(); i!=a.end(); i++){
        cout << *i << " ";
    }
    cout << endl;
}

//use -1 to indicate counterfeit
int index_counterfeit(unordered_set<int> a){
    int setsize = a.size();
    if (setsize==1) return 0;
    display(a);
    if (setsize%2!=0){
        a.insert(rand()%10 + 1);
        setsize++;
    }
    int half=setsize/2;
    unordered_set<int> l;
    unordered_set<int>  r;
    int count = 0;
    unordered_set<int>::iterator i;
    while (count<half){
        i=a.begin();
        l.insert(*i);
        a.erase(*i);
        count++;
    }
    count=0;
    while (count<half){
        i=a.begin();
        r.insert(*i);
        a.erase(*i);
        count++;
    }
    if (l.count(-1)>0){
        return index_counterfeit(l);
    }
    return index_counterfeit(r)+half;
}

int smallestk(int a[], int size, int h){
    int sum=0;
    int count=1;
    for (int i=0; i<size; i++){
        sum+=a[i];
        if (sum>h){
            sum=0;
            count++;
            i--;
        }
    }
    return count;
}

int bottleneck(int a[], int size, int k, int lowerbound, int upperbound){
    if (lowerbound==upperbound) return lowerbound;
    int target = (lowerbound+upperbound)/2;
    int numk = smallestk(a,size,target);
    cout << "when target is " << target << ", numk is " << numk << endl;
    if (numk>k){
        return bottleneck(a,size,k,target+1,upperbound);
    }
    else{
        return bottleneck(a,size,k,lowerbound,target);
    }
}

int sum(int a[], int size){
    int s = 0;
    for (int i=0; i<size; i++){
        s+=a[i];
    }
    return s;
}

int main() {
    srand(time(NULL));
    int a[]={4,6,2,-3,-5,9,-3,1};
    int* result=find_interval(a,8);
    cout << "(" << result[0] << "," << result[1] << ")" << endl;

    int b[]={0,1,2,3,4,5,6,-1,7,8,9,10};
    unordered_set<int> target(b,b+12);
    cout << "the index is " << index_counterfeit(target) << endl;

    int c[]={1,7,5,8,9,4,3,6};
    cout << "bottleneck is " << bottleneck(c,8,3,9,sum(c,8)) << endl;
	return 0;
}
