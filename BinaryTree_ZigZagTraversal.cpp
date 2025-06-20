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

vector<int> zigzagTraversal(node*root){
    vector<int>result;
    if(root==NULL){
        return result;
    }
    queue<node*>q;
    q.push(root);
    
    bool leftToRight = true;
    while(!q.empty()){
        int size = q.size();
        vector<int>ans(size);
        for(int i =0;i<size;i++){
            node*frontNode = q.front();
            q.pop();
            int index = leftToRight? i: size-i-1;
            ans[index]=frontNode->data;

            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }
        leftToRight =!leftToRight;
        for(auto i : ans){
            result.push_back(i);
        }
    }
    return result;
}


int main(){
 
 node*root;
 root = buildTree(root);

return 0;
}