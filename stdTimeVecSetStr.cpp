#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <set>
#include <string>
using namespace std;

int INFINITE = 1000;

struct Node{
    int x;
    int y;
    bool taxi;
    Node* right;
    Node* under;
};

struct Segment{
    int x;
    Segment* next;
};

int time_complete(int a[], int size){
    int sum1=a[0];
    int sum2=0;
    for (int i=1; i<size; i++){
        if (sum1>sum2) sum2+=a[i];
        else sum1+=a[i];
    }
    return (sum1>sum2 ? sum1 : sum2);
}

Node* construct(Node* head, int n){
    if (n<=0) return head;

    Node* nowright = new Node;
    Node* nowunder = new Node;
    nowright->y = head->y;
    nowunder->x = head->x;
    nowright->x = rand()%5 + head->x;
    nowunder->y = rand()%5 + head->y;

    nowright->taxi=false;
    nowunder->taxi=false;
    if (((int) rand()%2) == 0){
        nowright->taxi=true;
    }
    if (((int) rand()%2) == 0){
        nowunder->taxi=true;
    }

    nowright->right = NULL;
    nowright->under = NULL;
    nowunder->right = NULL;
    nowunder->under = NULL;

    nowright = construct(nowright, n-2);
    nowunder = construct(nowunder, n-2);
    head->right = nowright;
    head->under = nowunder;

    return head;
}

void displayInorder(Node* head){
    if (head==NULL) return;
    displayInorder(head->under);
    cout << "(" << head->x << "," << head->y << ")\n";
    displayInorder(head->right);
}

Node* setCompany(Node* head){
    if (head->under==NULL&&head->right==NULL) return head;
    if (((int) rand()%2)==0) return setCompany(head->under);
    return setCompany(head->right);
}

int time_walk(Node* head, Node* company){
    if (head==company) return 0;
    if (head->right==NULL&&head->under==NULL) return INFINITE;
    if (head->right==NULL){
        return head->under->y - head->y + time_walk(head->under, company);
    }
    if (head->under==NULL){
        return head->right->x - head->x + time_walk(head->right, company);
    }
    int t1 = head->right->x - head->x + time_walk(head->right, company);
    int t2 = head->under->y - head->y + time_walk(head->under, company);
    return (t2>t1? t1: t2);
}

int time_taxi(Node* head, Node* company){
    if (head==company) return 0;
    if (head->taxi) return time_walk(head,company)/2;
    if (head->right->taxi) return time_walk(head,head->right) + time_taxi(head->right, company);
    if (head->under->taxi) return time_walk(head,head->under) + time_taxi(head->under, company);
    return time_walk(head,company);
}

Segment* construct_ring(int n){
    Segment* head = new Segment;
    head->x = 1;
    Segment* prev = head;
    Segment* now;
    for (int i=2; i<=n; i++){
        now = new Segment;
        now->x = i;
        prev->next=now;
        prev=now;
    }
    now->next=head;
    return head;
}

void display(Segment* head){
    cout << head->x << " ";
    Segment* now = head->next;
    while (now!=head){
        cout << now->x << " ";
        now=now->next;
    }
    cout << endl;
}

Segment* magic(Segment* head, int k){
    if (k==0) return head;
    head->x = head->x + head->next->x;
    if (head->x > 100){
        head->x = head->x % 100;
    }
    Segment* now = head->next;
    while (now!=head){
        now->x = now->x + now->next->x;
        if (now->x > 100){
        now->x = now->x % 100;
    }
        now=now->next;
    }
    return magic(head,k-1);
}


set<double> find_elements(int w, int x, int y, int z){
    set<double> s;
    for (int i=w; i<=x; i++){
        for (int j=y; j<=z; j++){
            s.insert((i*1.0)/(j*1.0));
        }
    }
    return s;
}

int calculate(string s){
    int sum = s[0] - '0';
    for (int i=1; i<s.length(); i+=2){
        if (s[i]=='+') sum+= s[i+1]-'0';
        else if (s[i]=='*') sum*= s[i+1] - '0';
        else if (s[i]=='-') sum-= s[i+1] - '0';
    }
    return sum;
}

   int main()
   {
       srand(time(NULL));
       int a[]={2,4,5,9,7,11,8};
       cout << "time to complete is: " << time_complete(a,7) << endl;

    Node* head = new Node;
    head->x=0;
    head->y=0;
    head->taxi=false;
    head->right=NULL;
    head->under=NULL;
    head = construct(head,9);

    displayInorder(head);

    Node* company = setCompany(head);
    cout << "company position is: (" << company->x << ',' << company->y << ")\n";

    cout << "time to walk to company: " << time_walk(head,company) << endl;

    cout << "time to take a taxi to company: " << time_taxi(head,company) << endl;

    Segment* head = construct_ring(9);
    display(head);

    Segment* nhead;
    for (int i=1; i<5; i++){
        nhead = magic(head,1);
        cout << "magic" << i << ":\n";
        display(nhead);
        cout << endl;
    }

    set<double> s = find_elements(3,9,1,3);

    for (set<double>::iterator i=s.begin(); i!=s.end(); i++){
        cout << *i << " ";
    }
    cout << endl;

    cout << "sum is: " << calculate("1+2*3-4") << endl;
    return 0;
    }
