#include <iostream>
#include <climits>
#include <cmath>
using namespace std;
 class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left =NULL;
        right =NULL;
    }
 };

 node* bst_LCA(node*root, int a, int b){
    if(root==NULL){
        return NULL;
    }
    if(a>root->data && b> root->data){
        return bst_LCA(root->right,a,b);
    }
    if(a<root->data && b<root->data){
        return bst_LCA(root->left,a,b);
    }

    return root;
 }

int main() {
    node*root = new node(4);
    root->right = new node(5);
    root->left = new node(2);
    root->left->left =new node(1);
    root->left->right = new node(3);
    // inorder traversal is 1 2 3 4 5
    
    return 0;
}