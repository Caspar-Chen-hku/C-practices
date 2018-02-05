#include <iostream>
#include <time.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

struct Node{
    int val;
    Node* next;
};

struct Queue{
    Node* head;
    Node* tail;
    int len;
};

Queue enqueue(Queue &q, Node* node){
    if (q.len==0){
        q.head=node;
        q.tail=node;
        (q.len)++;
        node->next=NULL;
    }
    else{
        (q.tail)->next=node;
        q.tail=node;
        node->next=NULL;
        (q.len)++;
    }
    return q;
}

Queue construct(Queue& q, int n){
    Node* node;
    for (int i=0; i<n; i++){
        node = new Node;
        node->next=NULL;
        node->val = (int) rand()%100 + 1;
        q = enqueue(q, node);
    }
    return q;
}


void destruct(Queue& q){
    if (q.len==0) return;

    Node* current=q.head;
    Node* future=q.head->next;
    delete current;
    while(future!=NULL){
        current=future;
        future=future->next;
        delete current;
    }
    current=NULL;
    future=NULL;
    q.head=NULL;
    q.tail=NULL;
    q.len=0;
}

Queue dequeue(Queue q){
    if (q.len==0){
        cout << "queue is empty!" << endl;
        return q;
    }
    Node* result=q.head;
    q.head=result->next;
    cout << result->val << " is poped"<< endl;
    delete result;
    result=NULL;
    q.len--;
    if (q.len==0){
        q.head=NULL;
        q.tail=NULL;
    }
    return q;
}


int main() {
    srand(time(NULL));
    Queue q;

    Node* h = new Node;
    h->next=NULL;
    h->val=50;
    q.head=h;
    q.tail=h;
    q.len=1;

    q = construct(q,9);

   q = dequeue(q);
   q = dequeue(q);

   Node* node = new Node;
   node->val = (int) rand()%100+1;
   q = enqueue(q,node);
   cout << "head is " << q.head->val << endl;
   cout << "tail is " << q.tail->val << endl;

    destruct(q);
	return 0;
}
