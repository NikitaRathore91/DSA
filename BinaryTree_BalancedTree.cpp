/* A tree is called a balanced tree if the height diffeence of left and right subtree is less than or equal to 1 
for all the nodes present in tree*/
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
int height(node*root){
  if(root==NULL){
    return 0;
  }

  int left = height(root->left);
  int right = height(root->right);

  int ans = max(left,right)+1;
  return ans;
}


bool isBalancedTree(node*root){
    if(root==NULL){
        return true;
    }
    
    bool left = isBalancedTree(root->left);
    bool right = isBalancedTree(root->right);
    bool difference = height(root->left)-height(root->right)<=1;

    if(left&&right&&difference){
        return 1;
    }
    else{
        return 0;
    }
}

pair<bool,int> fastBalance(node*root){
    if(root==NULL){
        pair<bool,int>p = make_pair(true,0);
        return p;
    }

    pair<bool,int>left = fastBalance(root->left);
    pair<bool,int>right = fastBalance(root->right);

    bool leftans = left.first;
    bool rightans = right.first;
    bool diff = abs(left.second-right.second)<=1;

    pair<bool,int>ans;

    ans.second = max(left.second,right.second)+1;
    if(leftans&&rightans&&diff){
        ans.first = true;
    }
    else{
        ans.first = false;
    }
    return ans;
}

int main(){
 
 node*root;
 root = buildTree(root);

    return 0;
}