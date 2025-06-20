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

//levelOrder Traversal
void levelOrderTraversal(node* root) {
    if (root == NULL) {
        return;
    }

    queue<node*> q;
    q.push(root);
    q.push(NULL); // Indicates the end of the current level

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            // End of level, print new line
            cout << endl;

            // If there are more nodes to process, add another NULL to mark the next level
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            // Print the current node's data followed by a space
            cout << temp->data << " ";

            // Push left and right children if they exist
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}


node*buildTreeFromLevelOrderTransversal(node*root){
    
queue<node*>q;
cout<<"enter the data for the node ";
int x;
cin>>x;
root = new node(x);
q.push(root);

while(!q.empty()){
    node*temp =q.front();
    q.pop();

    cout<<"Enter the left node for "<<temp->data;
    int leftData;
    cin>>leftData;
    if(leftData!=-1){
        temp->left =new node(leftData);
        q.push(temp->left);
    }

    cout<<"Enter the right node for "<<temp->data;
    int rightData;
    cin>>rightData;
    if(rightData!=-1){
        temp->right =new node(rightData);
        q.push(temp->right);
    }
}


}

//In-order traversal

void inOrder(node*root){
  if(root==NULL){
    return;
  }
  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
}


int main(){
 
 node*root;

 root = buildTree(root);
 levelOrderTraversal(root);
    return 0;
}