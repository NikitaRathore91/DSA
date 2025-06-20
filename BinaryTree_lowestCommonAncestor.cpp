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
// vector<int>Path_p(node*root,node*p){
//   vector<int>ansP;
//   if(root==NULL){
//     return ansP;
//   }
//   if(root==p){
//     ansP.push_back(p->data);
//     return ansP;
//   }
//   ansP.push_back(root->data);
  
//   if(root->left){
//     vector<int>left = Path_p(root->left,p);
//   }
//   if(root->right){
//     vector<int>right=Path_p(root->right,p);
//   }

// }

node* lca(node*root,int p,int q){
  if(root==NULL){
    return NULL;
  }
  if(root->data==p || root->data==q){
    return root;
  }

  node*left = lca(root->left,p,q);
  node*right = lca(root->right,p,q);

  if(left!=NULL && right!=NULL){
    return root;
  }
  else if(left==NULL && right!=NULL){
    return right;
  }
  else if(right==NULL && left!=NULL){
    return left;
  }
  else{
    return NULL;  // both are null then return null
  }

}

int main(){
node*root;
root=buildTree(root);
 return 0;   
}