 #include<iostream>
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

 int findMin(node* root){
    node*temp = root;
   while(temp->left!=NULL){
       temp = temp->left;
   }
    int min = temp->data;
    return min;
 }

 int findMax(node*root){
     node*temp = root;
   while(temp->right!=NULL){
       temp = temp->right;
   }
    int max = temp->data;
    return max;
 }

 node* deleteFromBST(node* root, int d) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == d) {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Case 2: Only left child
        if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Only right child
        if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 4: Both children exist
        if (root->left != NULL && root->right != NULL) {
            int mini = findMin(root->right);  // Get minimum from right subtree
            root->data = mini;               // Replace current node's value
            root->right = deleteFromBST(root->right, mini); // Delete the duplicate
            return root;
        }
    }

    // Recursive calls for left and right subtrees
    if (d < root->data) {
        root->left = deleteFromBST(root->left, d);
    } else {
        root->right = deleteFromBST(root->right, d);
    }
    return root;
}


int main(){
  node*root = new node(8);
  root->right = new node(16);
  root->right->left =new node(10);
  root->right->left->left = new node(9);
  root->left = new node(4);
  root->left->right=new node(6);

 int mini = findMin(root);
 cout<<"Min is "<<mini<<endl;

 int maxx =findMax(root);
 cout<<"Max is "<<maxx<<endl;

 }