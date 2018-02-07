#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>
using namespace std;

  struct Node{
      int val;
      Node* next;
  };

   Node* construct(int size, int value){
      Node* head = new Node;
      head->val=value;
      Node* current=head;
      Node* now;
      for (int i=0; i<size-1; i++){
          now=new Node;
          now->val=value+i+1;
          current->next=now;
          now->next=NULL;
          current=now;
      }
      return head;
   }
   
   Node* construct_rand(int size){
       Node* head = new Node;
       head->val = rand()%100 +1;
       Node* current=head;
       Node* now;
       for (int i=0; i<size; i++){
           now = new Node;
           now->val = rand()%100 + 1;
           now->next=NULL;
           current->next=now;
           current=now;
       }
       return head;
   }
   
   void display(Node* head){
       Node* current=head;
       while (current!=NULL){
           cout << current->val << ' ';
           current=current->next;
       }
       cout << endl;
   }
   
   Node* reverse(Node* head){
       if (head==NULL||head->next==NULL) return head;
       Node* current = head;
       Node* prev = NULL;
       Node* future = head->next;
       current->next=prev;
       while (future!=NULL){
           prev=current;
           current=future;
           future=future->next;
           current->next=prev;
       }
       return current;
   }
   
   Node* find_reverse(Node* head, int N){
       Node* future= head;
       Node* current = head;
       for (int i=N; i>0; i--){
           future=future->next;
       }
       while (future!=NULL){
           current=current->next;
           future=future->next;
       }
       return current;
   }
   
   void delete_node(Node* target){
       Node* current=target->next;
       target->val=current->val;
       target->next=current->next;
       delete current;
       current = NULL;
   }
   
   void delete_list(Node* head){
       if (head==NULL) return;
       Node* current=head;
       Node* future=head->next;
       delete current;
       while (future!=NULL){
           current=future;
           future=future->next;
           delete current;
       }
       current=NULL;
       future=NULL;
   }
   
   Node* construct_circular(){
       Node* head = new Node;
       Node* future = new Node;
       head->val=1;
       head->next=future;
       future->val=2;
       Node* dummy = future;
       Node* now;
       for (int i=0; i<5; i++){
           now = new Node;
           now->val = i+3;
           dummy->next=now;
           dummy=now;
       }
       now->next=future;
       return head;
   }
   
   Node* find_intersect(Node* head){
       if (head==NULL||head->next==NULL) return NULL;
       Node* current=head;
       Node* future=head->next;
       while (current!=future&&future->next!=NULL){
           current=current->next;
           future=future->next->next;
       }
       if (current==future) return current;
       return NULL;
   }
   
   Node* insert_end(Node* head, Node* n){
       n->next=NULL;
       if (head==NULL){
           return n;
       }
       Node* current = head;
       while (current->next!=NULL){
           current=current->next;
       }
       current->next=n;
       return head;
   }
   
   Node* concat_list(Node* h1, Node* h2){
       if (h1==NULL) return h2;
       else if (h2==NULL) return h1;
       
       Node* result=NULL;
       Node* current1 = h1;
       Node* current2 = h2;
       Node* future1 = h1->next;
       Node* future2 = h2->next;
       while (current1!=NULL&&current2!=NULL){
           if (current1->val <= current2->val){
               result = insert_end(result,current1);
               current1=future1;
               if (current1==NULL) break;
               future1=future1->next;
           }
           else{
               result = insert_end(result,current2);
               current2=future2;
               if (current2==NULL) break;
               future2=future2->next;
           }
       }
       while (current1!=NULL){
           result = insert_end(result,current1);
               current1=future1;
               if (current1==NULL) break;
               future1=future1->next;
       }
       while (current2!=NULL){
          result = insert_end(result,current2);
               current2=future2;
               if (current2==NULL) break;
               future2=future2->next;
       }
       return result;
       
   }
   
   Node* findMiddle(Node* head){
       if (head==NULL||head->next==NULL) return head;
       Node* current = head;
       Node* future = head;
       while (future!=NULL && future->next!=NULL){
           current=current->next;
           future=future->next->next;
       }
       return current;
   }
   
   int main()
   {
       srand(time(NULL));
    Node* head = construct(6,1);
    display(head);
    
    Node* new_head = reverse(head);
    display(new_head);
    
    Node* middle = findMiddle(new_head);
    cout << middle->val << endl;
    
    Node* rand_head = construct_rand(6);
    
    
    Node* target = find_reverse(new_head, 2);
    
    cout << target->val << endl;
    
    delete_node(new_head->next);
    display(new_head);
    
    
    Node* circular_head = construct_circular();
    Node* found = find_intersect(circular_head);
    cout << found->val << endl;
    
    found = find_intersect(new_head);
    if (found==NULL) cout << "NULL" << endl;
    
    Node* list1 = construct(5,2);
    Node* list2 = construct(4,1);
    Node* concated = concat_list(list1, list2);
    display(concated);
    
    delete_list(new_head);
    delete_list(circular_head);
    delete_list(concated);
 
    return 0;
    }