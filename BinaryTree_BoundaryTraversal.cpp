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
//this is for printing the left side of the tree except the leaf nodes
void traversalLeft(node*root,vector<int>&ans){
    if((root==NULL)||(root->left==NULL&&root->right==NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->left){
        traversalLeft(root->left,ans);
    }
    else{
        traversalLeft(root->right,ans);
    }
}
//this is for printing the leaf nodes

void traversalLeaf(node*root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    if(root->left==NULL&&root->right==NULL){
        ans.push_back(root->data);
        return;
    }

    traversalLeaf(root->left,ans);
    traversalLeaf(root->right,ans);
}

//this is for printing the right side of the tree except the leaf nodes

void traversalRight(node*root,vector<int>&ans){
    if((root==NULL)||(root->left==NULL&&root->right==NULL)){
        return;
    }
  
    if(root->right){
        traversalRight(root->right,ans);
    }
    else{
        traversalRight(root->left,ans);
    }
      ans.push_back(root->data);
}

//this is combination of left,leaf,right
vector<int>boundary (node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    ans.push_back(root->data);
    //left
    traversalLeft(root->left,ans);
    //leaf
    traversalLeaf(root->left,ans);
    traversalLeaf(root->right,ans);
    //right
    traversalRight(root->right,ans);

    return ans;

}

int main(){
 
 node*root;

 root = buildTree(root);
 vector<int>answer = boundary(root);

   cout << "Boundary traversal of the tree: ";
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}