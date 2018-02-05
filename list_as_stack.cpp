#include <iostream>
#include <time.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

struct Node{
    int val;
    Node* next;
};

Node* push(Node* head, Node* node){
    if (head==NULL) return node;
    node->next=head;
    head=node;
    return head;
}

Node* construct(Node* head, int n){
    Node* node;
    for (int i=0; i<n; i++){
        node = new Node;
        node->next=NULL;
        node->val = (int) rand()%100 + 1;
        head = push(head, node);
    }
    return head;
}
    

void destruct(Node* head){
    if (head==NULL) return;
    
    Node* current=head;
    Node* future=head->next;
    delete current;
    while(future!=NULL){
        current=future;
        future=future->next;
        delete current;
    }
    current=NULL;
    future=NULL;
}

Node* pop(Node* head){
    Node* result=head;
    head=head->next;
    cout << result->val << " is poped"<< endl;
    return head;
}


int main() {
    srand(time(NULL));
    Node* head = new Node;
    head->next=NULL;
    head->val=50;
    head = construct(head,10);
    
   head=pop(head);
   head=pop(head);
   cout << "head is " << head->val << endl;
   
   Node* node = new Node;
   node->val = (int) rand()%100+1;
   head=push(head,node);
   cout << "head is " << head->val << endl;
    
    destruct(head);
    return 0;
}