#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* makeBST(node* &root,int d){
    if(root==NULL){
      return new node(d);
    }
    if(d<root->data){
        root->left = makeBST(root->left,d);
    }
    else{
        root->right =makeBST(root->right,d);
    }

    return root;}


void inputForBst(node* &root){
    int data;
    cout<<"Enter data for the root node ";
    cin>>data;
    while(data!=-1){
        root = makeBST(root, data);
        cout << "Enter next data (-1 to stop): ";
        cin >> data;
    }
        
    }


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

int main(){

 node*root = NULL;
 cout<<" input by which you want to create bst "<<endl;

 inputForBst(root);


 levelOrderTraversal(root);



}