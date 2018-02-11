#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
using namespace std;

int CAPACITY = 50;

struct double_stack{
    int* content;
    int top1;
    int top2;
};

double_stack constructor(){
    double_stack s;
    s.content = new int[CAPACITY];
    s.top1=-1;
    s.top2=CAPACITY;
    return s;
}

void display(double_stack s){
    if (s.top1==-1){
        cout << "stack1 is empty";
    }
    else{
        cout << "stack1: ";
        for (int i=0; i<=s.top1; i++){
        cout << s.content[i] << ' ';
       }
    }
    if (s.top2==CAPACITY){
        cout << "stack2 is empty\n";
    }
    else{
        cout << "\nstack2: ";
     for (int i=CAPACITY-1; i>=s.top2; i--){
        cout << s.content[i] << ' ';
       }
    cout << endl;
    }

}

int top(double_stack s){
    if (s.top1==-1&&s.top2==CAPACITY){
        cout << "s is empty!\n";
        return NULL;
    }
    int i = s.content[s.top1];
    int j = s.content[s.top2];
    if (s.top1==-1) return j;
    if (s.top2==CAPACITY) return i;
    return ((i<j)?j:i);
}

double_stack push(double_stack s, int n){
    if (s.top1 + 1 == s.top2){
        cout << "the stacks are full!\n";
        return s;
    }
    int i = top(s);
    if (s.content[s.top2]==i){
        s.top1++;
        s.content[s.top1] = n;
    }
    else{
        s.top2--;
        s.content[s.top2] = n;
    }
    display(s);
    return s;
}

double_stack pop(double_stack s){
    if (s.top1==-1&&s.top2==CAPACITY){
        cout << "the stacks are empty!\n";
        return s;
    }
    if (s.top1==-1){
        s.top2++;
        return s;
    }
    if (s.top2==CAPACITY){
        s.top1--;
        return s;
    }
    int i = s.content[s.top1];
    int j = s.content[s.top2];
    if (i<j){
        s.top2++;
    }
    else{
        s.top1--;
    }
    display(s);
    return s;
}

int main() {
    double_stack s = constructor();
    srand(time(NULL));
    int temp;
    for (int i=0; i<CAPACITY/2; i++){
        cout << "round" << i << endl;
        temp = rand()%CAPACITY;
        s = push(s,temp);
        cout << endl;
    }


	return 0;
}
