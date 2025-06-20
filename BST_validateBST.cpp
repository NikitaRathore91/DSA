#include<iostream>
#include<vector>
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
 // this will give wrong answer 
//  bool isValid(node*root){
//     if(root==NULL){
//         return true;
//     }
//     if(root->left!=NULL&& root->left->data>=root->data){
//         return false;
//     }
//     if(root->right!=NULL&& root->right->data<=root->data){
//         return false;
//     }

//     return isValid(root->left) && isValid(root->right);
    
//  } 

 // approach 1
 //using inorder traversal
 //in bst the inorder traversal in sorted
void inOrder(node*root,vector<int>&a){
 
     if(root==NULL){
        return;
     }
    inOrder(root->left,a);
    a.push_back(root->data);
    inOrder(root->right,a);

}

bool isValid(node*root){
    vector<int>inOrderr;
    inOrder(root,inOrderr);
    int n = inOrderr.size();
    for(int i = 0;i<n-1;i++){
        if(inOrderr[i]>=inOrderr[i+1]){
            return false;
        }
    }
    return true;
}


// Approach 2 
// we will use range and check for each node if it in in the range 
// for the root node it has range of(-infinite,infinite)

bool isBST(node*root,long long min,long long max){
    if(root==NULL){
        return true;
    }

    if(root->data < max && root->data>min){
        return isBST(root->left,min,root->data)&& isBST(root->right,root->data,max);
    }
    else{
        return false;
    }

   
}

 int main(){
    node*root = new node(4);
    root->right = new node(5);
    root->left = new node(2);
    root->left->left =new node(1);
    root->left->right = new node(3);
    //for approach 1
    bool abc = isValid(root);
    cout<<abc;

    //for approach 2
    long long largeValue = 9223372036854775807;
    long long smallValue = -9223372036854775807;
    /*i did not use INT_MAX and INT_MIN as one testcase in leetcode has root = INT_MAX and it was 
      one of the edge case, we needed much larger range
     */
    bool isItValidOrNot = isBST(root,smallValue,largeValue);
    cout<<isItValidOrNot;


 }