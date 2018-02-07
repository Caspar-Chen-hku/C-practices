#include <iostream>
#include <stack>
#include <time.h>
#include <stdlib.h>
using namespace std;

stack<int> reverse(stack<int> s){
    if (s.empty()) return s;
    int top1 = s.top();
    s.pop();
    if (s.empty()){
        s.push(top1);
        return s;
    }
    s = reverse(s);
    int top2 = s.top();
    s.pop();
    s = reverse(s);
    s.push(top1);
    s = reverse(s);
    s.push(top2);
    return s;
}

stack<int> sort(stack<int> s){
    if (s.empty()) return s;
    int top1 = s.top();
    s.pop();
    if (s.empty()){
        s.push(top1);
        return s;
    }
    s = sort(s);
    int top2 = s.top();
    s.pop();
    if (top1>top2){
        s.push(top1);
        s =sort(s);
        s.push(top2);
    }
    else{
        s.push(top2);
        s=sort(s);
        s.push(top1);
    }
    return s;
}

void display(stack<int> s){
    while (!s.empty()){
        cout << s.top() << ' ';
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    srand(time(NULL));
    for (int i=1; i<=5; i++){
        s.push((int) rand()%10);
    }
    display(s);
    
    //s=reverse(s);
    s = sort(s);
    
    display(s);
    return 0;
}