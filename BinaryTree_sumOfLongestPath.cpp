#include<bits/stdc++.h>
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
void solve(node*root,int sum,int &maxSum,int length,int maxLength){
   if(root==NULL){
   if(length>maxLength){
    maxLength =length;
    sum=maxSum;
   }
   else if(length==maxLength){
    maxSum = max(sum,maxSum);
   }
   return;
   }

   sum = sum+root->data;

   solve(root->left,sum,maxSum,length+1,maxLength);
   solve(root->right,sum,maxSum,length+1,maxLength);
}
int main(){
  node*root;
  root =buildTree(root);
  int sum=0;
  int maxSum=INT_MIN;
  int length=0;
  int maxlength =0;

}