#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;

    node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

int totalNodes(node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + totalNodes(root->left) + totalNodes(root->right);
}

bool isCBT(node*root,int n,int i){
    if(root==NULL){
        return true;
    }
    if(i>=n){
        return false;                     
    }

    return isCBT(root->left,n,2*i+1) && isCBT(root->right,n,2*i+2);
}

bool isMax(node*root){
    if(root==NULL){
        return true;
    }
    if(root->left && root->left->data > root->data){
        return false;
    }
    if(root->right && root->right->data > root->data){
        return false;
    }

    return isMax(root->left) && isMax(root->right);
}

int main(){
    node*root = new node(15);
    root->left = new node(14);
    root->right = new node(13);
    root->left->left = new node(9);
    root->left->right = new node(10);
    root->right->left = new node(11);
    root->right->right = new node(12);
    root->left->left->left = new node(7);
    root->left->left->right = new node(8);

    int nodes = totalNodes(root);

    if(isCBT(root,nodes,0)&&isMax(root)){
        cout<<"this is a valid max heap"<<endl;
    } 
    else{
        cout<<"this is not a valid max heap "<<endl;
    }
}