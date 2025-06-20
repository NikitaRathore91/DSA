#include <bits/stdc++.h>
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

int height(node*root){
    if(root==NULL){
        return 0;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);

    int ans = max(leftheight,rightheight)+1;
    return ans;

}

int diameterOfTree(node*root){
    if(root==NULL){
        return 0;
    }

    int op1 = diameterOfTree(root->left);
    int op2 = diameterOfTree(root->right);
    int op3 = height(root->left)+height(root->right)+1;

    int ans = max(op1,max(op2,op3))+1;
    return ans;
}

pair<int,int> diameterFast(node*root){
    if(root == NULL){
        pair<int,int>p = make_pair(0,0);
        return p;

    }
    pair<int,int>left = diameterFast(root->left);
    pair<int,int>right =diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 =left.second + right.second +1;
    
    pair<int,int>ans;
    ans.first = max(op1, max(op2,op3));
    ans.second = max(left.second, right.second)+1;

    return ans;
    }
    
int main(){
 
 node*root;
 root = buildTree(root);
 int dia = diameterOfTree(root);
 cout<<dia;
    return 0;
}