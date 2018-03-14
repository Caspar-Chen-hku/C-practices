#include <iostream>
#include <map>
using namespace std;

int mult_by_pow_2(int number, int power)
{
    return number<<power;
}
int AND(int a,int b){
    return a&b;
}
int OR(int a,int b){
    return a|b;
}
int XOR(int a,int b){
    return a^b;
}

void flip(int* a,int* b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int unique(int arr[], int n){
    map<int,int> r;
    for (int i=0; i<n; i++){
        if (r.count(arr[i])>0){
            r[arr[i]]++;
        }
        else{
            r[arr[i]]=1;
        }
    }
    for (map<int,int>::iterator i=r.begin(); i!=r.end(); i++){
        if ((*i).second==1) return (*i).first;
    }
}

void test(){
    if (1) cout << "1 is true\n";
    if (0) cout << "0 is true\n";
}

bool isPow2(int a){
    return !(a&(a-1));
}

int unique_bit(int arr[],int n){
    int result = 0;
    for (int i=0; i<n; i++){
        result^=arr[i];
    }
    return result;
}
   int main()
   {
    cout << mult_by_pow_2(10,2) << endl;
    cout << mult_by_pow_2(128,1) << endl;
    cout << AND(72,184) << endl;
    cout << OR(72,184) << endl;
    unsigned int max = ~0;
    cout << max << endl;
    cout << XOR(72,184) << endl;
    unsigned int temp = 0;
    cout << temp-1 << endl;
    cout << ((unsigned int )0) - 1 << endl;

    int a=5;
    int b=10;
    flip(&a,&b);
    cout << a << "," << b << endl;

    cout <<false << endl;
    cout << isPow2(32);
    cout << isPow2(88);

    int arr[] = {2,4,7,8,5,7,4,5,2};
    cout << unique(arr,9) << endl;
    cout << unique_bit(arr,9) << endl;
    test();
    return 0;
    }
