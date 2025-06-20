#include<iostream>
#include<queue>
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

int heightOfTree(node*root){
    int cnt = 0;
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL&&root->right==NULL){
        return cnt+1;
    }

    if(root->left!=NULL || root->right!=NULL){
        cnt++;
        if(root->left){
            heightOfTree(root->left);
        }
        else if( root->right){
            heightOfTree(root->right);
        }
    }
}

int main(){
 
 node*root;
 root = buildTree(root);

 int height = heightOfTree(root);
 cout<<height;
    return 0;
}