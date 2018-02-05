#include <iostream>
#include <time.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

Node* insert_node(Node* root, Node* node){
    if (root==NULL) return node;
    Node* newnode;
    if (node->val > root->val){
        newnode = insert_node(root->right,node);
        root->right=newnode;
        newnode->parent=root;
    }
    else{
        newnode = insert_node(root->left,node);
        root->left=newnode;
        newnode->parent=root;
    }
    return root;
}

void construct(Node* root, int n){
    Node* node;
    for (int i=0; i<n; i++){
        node = new Node;
        node->left=NULL;
        node->right=NULL;
        node->val = (int) rand()%100 + 1;
        root = insert_node(root, node);
    }
}

void inorder_traversal(Node* root){
    if (root==NULL) return;
    inorder_traversal(root->left);
    cout << root->val << ' ';
    inorder_traversal(root->right);
    
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

void delete_node(Node* node){
    Node* temp;
    if (node->left==NULL){
        if (node->parent->left==node){
            temp = node->right;
            temp->parent=node->parent;
            node->parent->left=temp;
        }
        else{
            temp = node->right;
            temp->parent=node->parent;
            node->parent->right=temp;
        }
    }
    else if (node->right==NULL){
        if (node->parent->left==node){
            temp = node->left;
            temp->parent=node->parent;
            node->parent->left=temp;
        }
        else{
            temp = node->left;
            temp->parent=node->parent;
            node->parent->right=temp;
        }
    }
    else{
        if (node->parent->left==node){
            temp=node->right;
            temp->parent=node->parent;
            node->parent->left=temp;
            temp->left=node->left;
            node->left->parent=temp;
        }
        else{
             temp=node->left;
            temp->parent=node->parent;
            node->parent->right=temp;
            temp->right=node->right;
            node->right->parent=temp;
        }
    }
    delete node;
    node = NULL;
}


int main() {
    srand(time(NULL));
    Node* root = new Node;
    root->left=NULL;
    root->right=NULL;
    root->parent=NULL;
    root->val=50;
    construct(root,10);
    
    inorder_traversal(root);
    cout << endl;
    
    delete_node(root->left);
    inorder_traversal(root);
    cout << endl;
    
    destruct(root);
    return 0;
}