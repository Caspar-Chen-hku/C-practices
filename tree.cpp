##include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

void construct(Node* root, int n){
    if (n<2) {
        root->left=NULL;
        root->right=NULL;
        return;
    }
    
    Node* l_child = new Node;
    Node* r_child = new Node;
    
    l_child->val = (int) rand()%100 + 1;
    
    r_child->val = (int) rand()%100 + 1;
    
    root->left = l_child;
    root->right = r_child;
    
    construct(l_child,(int)n/2);
    construct(r_child,(int)n/2);
}

Node* insert_node(Node* root, Node* node){
    if (root==NULL) {
        return node;
    }
    if (node->val > root->val){
        root->right = insert_node(root->right,node);
    }
   else{
       root->left = insert_node(root->left,node);
   }
   return root;
}

void construct_bisearch(Node* root, int n){
   Node* node;
   for (int i=0; i<n; i++){
       node = new Node;
       node->val = (int) rand()%100 + 1;
       node->left=NULL;
       node->right=NULL;
       root = insert_node(root, node);
       }
}

void construct_bisearch_static(Node* root, int a[], int size){
    Node* node;
   for (int i=0; i<size; i++){
       node = new Node;
       node->val = a[i];
       node->left=NULL;
       node->right=NULL;
       root = insert_node(root, node);
       }
}

void preorder_traversal(Node* root){
    if (root==NULL) return;
    cout << root->val << ' ';
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal(Node* root){
    if (root==NULL) return;
    inorder_traversal(root->left);
    cout << root->val << ' ';
    inorder_traversal(root->right);
    
}

void postorder_traversal(Node* root){
    if (root==NULL) return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->val << ' ';
}

void BFS(Node* root){
    if (root==NULL) return;
    queue<Node*> q;
    q.push(root);
    Node* temp;
    while (!q.empty()){
        temp=q.front();
        q.pop();
        cout << temp->val << ' ';
        if (temp->left!=NULL) q.push(temp->left);
        if (temp->right!=NULL) q.push(temp->right);
    }
    cout << endl;
}

int get_depth(Node* root){
    if (root==NULL) return -1;
    int ldepth = get_depth(root->left);
    int rdepth = get_depth(root->right);
    if (ldepth>rdepth) return ldepth+1;
    return rdepth+1;
}

bool balanced(Node* root){
    if (root==NULL) return true;
    int diff =  abs(get_depth(root->left)-get_depth(root->right));
    cout << "difference is: " << diff << endl;
    return (diff<=1&&balanced(root->left)&&balanced(root->right));
}

void destruct(Node* root){
    if (root==NULL) return;
    
    Node* l = root->left;
    Node* r = root->right;
    delete root;
    root = NULL;
    destruct(l);
    destruct(r);
}

Node* common_ancestor(Node* root, Node* n1, Node* n2){
    if (n1->val < root->val && n2->val < root->val){
        return common_ancestor(root->left, n1, n2);
    }
    else if (n1->val > root->val && n2->val > root->val){
        return common_ancestor(root->right, n1, n2); 
    }
    return root;
}

int leaf_num(Node* root){
    if (root==NULL) return 0;
    if (root->left==NULL&&root->right==NULL) return 1;
    return leaf_num(root->left) + leaf_num(root->right);
}

int node_num(Node* root){
    if (root==NULL) return 0;
    return node_num(root->left) + node_num(root->right) + 1;
}

Node* mirror(Node* root){
    if (root==NULL) return NULL;
    Node* lchild = mirror(root->left);
    Node* rchild = mirror(root->right);
    root->right = lchild;
    root->left = rchild;
    return root;
}

int min(Node* root){
    Node* now=root;
    while(now->left!=NULL){
        now=now->left;
    }
    return now->val;
}

int max(Node* root){
    Node* now = root;
    while (now->right!=NULL){
        now=now->right;
    }
    return now->val;
}


Node* max_node(Node* head){
    if (head==NULL) return NULL;
    Node* now = head;
    while (now->right!=NULL){
        now=now->right;
    }
    return now;
}

Node* findMiddle(Node* root,int target){
    if (root==NULL) return NULL;
    if (target==root->val) return root;
    else if (target > root->val){
        if (root->right!=NULL) return findMiddle(root->right,target);
        return root;
    }
    else{
        if (root->left!=NULL) return findMiddle(root->left,target);
        return root;
    }
}

Node* to_double_list(Node* root){
    if (root==NULL) return NULL;
    Node* headl = to_double_list(root->left);
    Node* headr = to_double_list(root->right);
    Node* maxl = max_node(headl);
    
    if (maxl==NULL&&headr==NULL){
        return root;
    }
    if (maxl==NULL){
        
        root->right=headr;
        headr->left=root;
        return root;
    }
    if (headr==NULL){
        maxl->right=root;
        root->left=maxl;
        return headl;
    }
    maxl->right=root;
    root->left=maxl;
    root->right=headr;
    headr->left=root;
    return headl;
}

void display_list(Node* head){
    if (head==NULL) return;
    Node* current=head;
    while (current!=NULL){
        cout << current->val << " ";
        current=current->right;
    }
    cout << endl;
}

void find_path(Node* root, int sum){
    if ((sum<0)||(root==NULL&&sum!=0)||(root!=NULL&&sum<root->val)){
        cout << "this path is invalid" << endl;
        return;
    }
    if (root==NULL&&sum==0){
        cout << "this path is valid" << endl;
        return;
    }
    int temp = root->val;
    cout << temp << " ";
    find_path(root->left,sum-temp);
    find_path(root->right,sum-temp);
}

int main() {
    
    srand (time(NULL));
    Node* root = new Node;
    root->val = 50;
    root->left=NULL;
    root->right=NULL;
    //construct_bisearch(root,10);
    
    int a[] = {28,89,20,36,64,99,26,42,57,33,15,110,75};
    construct_bisearch_static(root,a,13);
    

    cout << "Preorder traversal of tree: ";
    preorder_traversal(root);
    cout << endl;
    
    cout << "Inorder traversal of tree: ";
    inorder_traversal(root);
    cout << endl;
    
    
    cout << "Postorder traversal of tree: ";
    postorder_traversal(root);
    cout << endl;
    
    
    cout << "depth of the tree: ";
    cout << get_depth(root) << endl;
    
    Node* common = common_ancestor(root, root->left->left->right, root->left->right);
    
    cout << "common ancestor of the two specific nodes: ";
    cout << common->val << endl;
    
    cout << "number of leaves of the tree: ";
    cout << leaf_num(root) << endl;
    
    cout << "number of nodes of the tree: ";
   cout << node_num(root) << endl;
   
   cout << "BFS: ";
   BFS(root);
   
   if (balanced(root)) cout<< "this tree is balanced!" << endl;
    
    root = mirror(root);
    
    cout << "Inorder traversal of the mirror tree: "
    inorder_traversal(root);
    cout << endl;
    
    int target = (max(root)+min(root))/2;
    Node* found = findMiddle(root,target);
    cout << "target is " << found->val << endl;
    
    Node* head = to_double_list(root);
    display_list(head);
    find_path(root, 156);
    
    destruct(root);
    common = NULL;
    return 0;
}