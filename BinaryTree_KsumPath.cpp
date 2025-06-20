/*
Given a binary tree and an integer k, the task is to count the number of paths in the tree such that 
the sum of the nodes in each path equals k. A path can start from any node and end at any node and must be downward only.*/
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;

    node(int x){
        data=x;
        left=NULL;
        right=NULL;
    } 
};
node*buildTree(node*root){
    cout<<"enter the data for node ->";
    int data;
    cin>>data;

    root = new node(data);
    if(data == -1){
        return NULL;
    }

    cout<<" Enter the data for the left ->";
    root->left = buildTree(root->left);
    cout<<"Enter the data for the right ->";
    root->right =buildTree(root->right);

    return root;

}

void kSumPath(node*root,int &count,vector<int>path,int k){
   if(root==NULL){
    return;
   }
   path.push_back(root->data);
   kSumPath(root->left,count,path,k);
   kSumPath(root->right,count,path,k);

   int size=path.size();
   int sum =0;
   for(int i=size-1;i<=0;i--){
    sum=sum+path[i];
    if(sum==k){
        count++;
    }
   }
   path.pop_back();
}
int main(){
  node*root;
  root=buildTree(root);
  int count =0;
  vector<int>path;
}