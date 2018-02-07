#include <iostream>
#include <stack>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct Stackq{
    stack<int> qin;
    stack<int> qout;
};

Stackq* construct(int size){
    Stackq* q = new Stackq;
    int val;
    for (int i=0; i<size; i++){
        val  = rand()%50 + 1;
        q->qin.push(val);
    }
    return q;
}

Stackq* transfer(Stackq* q){
    while (!q->qin.empty()){
        q->qout.push(q->qin.top());
        q->qin.pop();
    }
    return q;
}

Stackq* enqueue(Stackq* q,int i){
    q->qin.push(i);
    return q;
}

Stackq* dequeue(Stackq* q){
    if (q->qout.empty()) q=transfer(q);
    if (q->qout.empty()){
        cout << "the queue is empty!" << endl;
        return NULL;
    }
    q->qout.pop();
    return q;
}

void display(Stackq* q){
    while (!q->qout.empty()){
        cout << q->qout.top() << ' ';
        q->qout.pop();
    }
    q = transfer(q);
    cout << ' ';
    while (!q->qout.empty()){
        cout << q->qout.top() << ' ';
        q->qout.pop();
    }
    cout << endl;
}

int main() {
    srand(time(NULL));
    Stackq* q = construct(8);
    
    q = enqueue(q,30);
    q = enqueue(q,20);
    
    q = dequeue(q);
    q = dequeue(q);
    display(q);
    
    return 0;
}