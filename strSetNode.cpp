#include <iostream>
#include <string>
#include <set>
#include <stdlib.h>
#include <time.h>
using namespace std;

char valid[]={'0','1','2','3','4','5','6','7','8','9','(','+','*','-','/',')','='};
set<char> stotal(valid,valid+17);
set<char> sfirst(valid,valid+10);
set<char> ssecond(valid+10,valid+17);

struct Node{
    int val;
    Node* next;
};

void duplicate(int a[], int size){
    set<int> s;
    int ssize=0;
    for (int i=0; i<size; i++){
        s.insert(a[i]);
        if (s.size()==ssize){
            cout << "duplicate!\n";
            return;
        }
        ssize++;
    }
    cout << "not duplicate!\n";
}

void printArrange(string s, int head, int tail){
    if (head==tail){
        cout << s << endl;
        return;
    }
    int temp;
    for (int i=head; i<tail; i++){
        temp=s[head]; s[head]=s[i]; s[i]=temp;
        printArrange(s,head+1,tail);
        temp=s[head]; s[head]=s[i]; s[i]=temp;
    }
}

int min_int(int a, int b, int c){
    if (a<b){
        if (a<c) return a;
        return c;
    }
    if (b<c) return b;
    return c;
}

int distStr(string a, string b){
    if (a==b) return 0;
    if (a.empty()) return b.length();
    if (b.empty()) return a.length();
    string tempa = a.substr(1);
    string tempb = b.substr(1);
    int m1 = distStr(a,tempb) + 1;
    int m2 = distStr(tempa,b) + 1;
    int m3 = distStr(tempa,tempb);
    if (a[0]!=b[0]) m3++;
    return min_int(m1,m2,m3);
}

bool validExpression(string a){
    if (sfirst.count(a[0])==0 && a[0]!='(') return false;
    bool paren=false;
    if (a[0]=='(') paren=true;
    for (int i=1; i<a.length(); i++){
        if (stotal.count(a[i])==0) return false;
        if (sfirst.count(a[i-1])>0 && sfirst.count(a[i])>0) return false;
        if (ssecond.count(a[i-1])>0 && ssecond.count(a[i])>0 && a[i-1]!=')') return false;
        if (a[i]==')') paren=!paren;
    }
    return !paren;
}

Node* construct_circle(int n){
    Node* head = new Node;
    head->val=1;
    Node* now;
    Node* prev = head;
    for (int i=2; i<=n; i++){
        now = new Node;
        now->val = i;
        prev->next=now;
        prev=now;
    }
    now->next=head;
    return head;
}

Node* construct_rand(int n){
    Node* head = new Node;
    head->val=1;
    Node* now;
    Node* prev = head;
    for (int i=2; i<=n; i++){
        now = new Node;
        now->val = rand()%n;
        prev->next=now;
        prev=now;
    }
    now->next=head;
    return head;
}

Node* next_m(Node* head, int m){
    if (head->next==head) return head;
    Node* now = head;
    for (int i=1; i<m; i++){
        now=now->next;
    }
    return now;
}

Node* remove_node(Node* target){
    if (target->next==target) return NULL;
    Node* future = target->next;
    target->val=future->val;
    target->next=future->next;
    return target;
}

void popSequence(int n, int m){
    Node* head = construct_circle(n);
    Node* target = head;
    while (target!=NULL){
        target=next_m(target,m);
        cout << target->val << ' ';
        target=remove_node(target);
    }
    cout << endl;
}

void display_circular(Node* head){
    cout << head->val << ' ';
    Node* now=head->next;
    while (now!=head){
        cout << now->val << ' ';
        now=now->next;
    }
    cout << endl;
}

Node* delete_duplicate(Node* head){
    set<int> s;
    s.insert(head->val);
    int vol=1;
    Node* now=head->next;
    while (now!=head){
        s.insert(now->val);
        if (s.size()==vol){
            now = remove_node(now);
            continue;
        }
        vol++;
        now=now->next;
    }
    return head;
}
   int main()
   {
    int a[]={1,2,3,4,5,6};
    int b[]={1,2,3,4,5,4};

    cout << "whether there is duplicate element:\n";
    duplicate(a,6);
    duplicate(b,6);

    cout << "\narrangement of array:\n";
    printArrange("love",0,3);

    cout << "\nDistance between strings: " << distStr("love","ova") << endl;

    set<char>::iterator i;
    for (i=stotal.begin(); i!=stotal.end(); i++){
        cout << *i;
    }
    cout << endl;
    for (i=sfirst.begin(); i!=sfirst.end(); i++){
        cout << *i;
    }
    cout << endl;
    for (i=ssecond.begin(); i!=ssecond.end(); i++){
        cout << *i;
    }
    cout << endl;

    cout << "this expression is ";
    if (validExpression("(1+2)*3=9")){
        cout << "valid\n";
    }
    else cout << "invalid\n";

    cout << "this expression is ";
    if (validExpression("1+2*=9")){
        cout << "valid\n";
    }
    else cout << "invalid\n";


    cout << "pop sequence: ";
    popSequence(9,5);

    Node* head = construct_rand(9);
    cout << "the original list is: ";
    display_circular(head);

    cout << "the list after deleting the duplicates: ";
    head = delete_duplicate(head);
    display_circular(head);
    return 0;
    }
