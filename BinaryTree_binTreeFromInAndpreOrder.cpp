#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;

    node(int x){
        data=x;
        left=NULL;
        right =NULL;
    }
};
int findPosition(int in[],int inorderStart,int inorderEnd,int element){
  for(int i = inorderStart;i<=inorderEnd;i++){
    if(in[i]==element){
        return i;
    }
  }
  return -1;
}

node*buildTree(int &index,int in[],int pre[],int inorderStart,int inorderEnd,int n){
     if(index>=n || inorderStart>inorderEnd){
        return NULL;
     }
     int element = pre[index++];
     node*root =new node(element);

     int position = findPosition(in,inorderStart,inorderEnd,element);

     root->left = buildTree(index,in,pre,inorderStart,position-1,n);
     root->right =buildTree(index,in,pre,position+1,inorderEnd,n);

     return root;
}

void printPostOrder(node*root){
    if(root==NULL){
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<" ";
}
int main(){
    int inOrd[] ={3,1,4,0,5,2};
    int preOrd[] ={0,1,3,4,2,5};
    // output -> print post order = {3 4 1 5 2 0}
    int n = sizeof(inOrd)/sizeof(int);
    int preOrderIndex = 0;

    node*root;
    root = buildTree(preOrderIndex,inOrd,preOrd,0,n-1,n);

    printPostOrder(root);
    return 0;
}