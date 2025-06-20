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

void inorder(node*root,int k,int &value,int &i){
    if(root==NULL){
        return;
    }
    inorder(root->left,k,value,i);
    i++;
    if(i==k){
         value = root->data; 
    }
    inorder(root->right,k,value,i);
}

int main() {
    node*root = new node(4);
    root->right = new node(5);
    root->left = new node(2);
    root->left->left =new node(1);
    root->left->right = new node(3);
    // inorder traversal is 1 2 3 4 5

    int k = 3;
    int value ;
    int i =0;
    inorder(root,k,value,i);
    cout<<value;


    return 0;
}