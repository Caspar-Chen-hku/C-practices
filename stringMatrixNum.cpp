#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int SIZE = 2;

//find the smallest k elements of an array
vector<int> find_smallest_k(int a[], int size, int k){
    vector<int> arr;
    int max = 0;
    int index;
    int temp;
    for (int i=0; i<size; i++){
        if (arr.size()<k){
            arr.push_back(a[i]);
            if (a[i]>max){
                max=a[i];
                index=i;
            }
            continue;
        }
        if (a[i]>=max) continue;
        arr[index]=a[i];
        max=a[i];
    }
    return arr;
}

string reverse(string s, int l, int r){
    char temp;
    for (int i=l; i<=(r+l)/2; i++){
        temp=s[i];
        s[i]=s[l+r-i];
        s[l+r-i]=temp;
    }
    return s;
}

void reverse_word(string s){
    int len=s.length();
    s = reverse(s,0,len-1);
    cout << "after totally reversed: " << s << endl;

    int left=0;
    int right=0;
    while (left<len){
        while (s[right+1]!=' '&&right<len-1) right++;
        s = reverse(s,left,right);
        left=right+2;
        right=left;
    }
    cout << "result: " << s << endl;
}

void find_sum(int a[], int size, int target){
    int i=0;
    int j=size-1;
    int sum;
    while (i<j){
        sum=a[i]+a[j];
        if (sum==target){
            cout << '(' <<i << ',' << j << ')' << endl;
            return;
        }
        else if (sum<target){
            i++;
        }
        else{
            j--;
        }
    }
    cout << "no such pair" << endl;
}

set<char> find_unique(string str){
    set<char> s;
    set<char> temp;
    set<char>::iterator it;
    for (int i=0; i<str.length(); i++){
        if (temp.count(str[i])>0){
            it = s.find(str[i]);
            if (it!=s.end()) s.erase(it);
            continue;
        }
        s.insert(str[i]);
        temp.insert(str[i]);
    }
    return s;
}

int** matrix_multiply(int** a, int** b){
    int** result = new int*[SIZE];
    for (int i=0; i<SIZE; i++){
        result[i] = new int[SIZE];
    }
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            result[i][j] = 0;
            for (int k=0; k<SIZE; k++){
                result[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    return result;
}

int** matrix_power(int **a,int n){
    if (n==1) return a;
    if (n==2) return matrix_multiply(a,a);
    int** temp = matrix_power(a,n/2);
    int** result = matrix_multiply(temp,temp);
    if (n%2==1) return matrix_multiply(result,a);
    return result;
}

void display_matrix(int** a){
    cout << "[ ";
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            cout << a[i][j] << " ";
        }
        cout << ";";
    }
    cout << " ]" << endl;
}

int one_appears(int n){
    if (n<10){
        return 1;
    }
    int lsb = n%10;
    int remaind = n/10;
    int temp = one_appears(remaind);
    if (lsb!=0){
        if (remaind%10==1){
            return (remaind+1)*(temp+1);
        }
        return (remaind+1) + 10*temp;
    }
    else{
        if (remaind%10==1){
            remaind + temp*(remaind+1);
        }
        return remaind + 10*temp;
    }
}

int int_power(int n, int k){
    if (k==1) return n;
    if (k==2) return n*n;
    int temp = int_power(n,k/2);
    int result = temp*temp;
    if (k%2==1){
        return result*n;
    }
    return result;
}

int one_appears_stupid(int n){
 if (n==0) return 0;
 if (n<10) return 1;
 int msb=n;
 int index=0;
 while (msb>=10){
     msb/=10;
     index++;
 }
 int ten_power = int_power(10,index);
 int remain = n-ten_power*msb;

 if (msb==1){
     return remain+1+one_appears_stupid(remain);
 }
 return ten_power+one_appears_stupid(remain);
}

void display_set(set<int>  s){
    for (set<int>::iterator i=s.begin(); i!=s.end(); i++){
        cout << *i << ' ';
    }
    cout << endl;
}

void all_arrays(int n){
    int l=1;
    int r=2;
    int sum=3;
    set<int> s;
    s.insert(1);
    s.insert(2);
    while (l<(n+1)/2&&l<r){
        if (sum<n){
            r++;
            sum+=r;
            s.insert(r);
        }
        else if (sum>n){
            sum-=l;
            s.erase(s.find(l));
            l++;
        }
        else{
            display_set(s);
            s.erase(s.find(l));
            sum-=l;
            l++;
        }
    }
}



int main() {
    reverse_word("I am a student");
    int a[]={1,2,4,7,9,13,16,18};
    find_sum(a,8,15);

    set<char> s = find_unique("oh it's so silly");
    for (auto i=s.begin(); i!=s.end(); i++){
        cout << *i;
    }
    cout << endl;

    int** a = new int*[SIZE];
    for (int i=0; i<SIZE; i++){
        a[i] = new int[SIZE];
        if (i==0){
            a[i][0]=1; a[i][1] = 1;
        }
        else{
            a[i][0]=1; a[i][1] = 0;
        }
    }
    int** result = matrix_power(a,10);
    display_matrix(result);

    cout << one_appears(21345) << endl;
    cout  << one_appears_stupid(21345) << endl;

    all_arrays(15);
	return 0;
}
