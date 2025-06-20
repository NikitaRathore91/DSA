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

 bool searchForNodeInBst(node* root,int d){
      if(root==NULL){
        return false;
      }
      if(root->data==d){
        return true;
      }
     if(d>root->data){
        return searchForNodeInBst(root->right,d);
     }
     else{
        return searchForNodeInBst(root->left,d);
     }
 }
 int main(){
  node*root = new node(8);
  root->right = new node(16);
  root->right->left =new node(10);
  root->right->left->left = new node(9);
  root->left = new node(4);
  root->left->right=new node(6);

  bool search6 = searchForNodeInBst(root,6);
  bool search18= searchForNodeInBst(root,18);

  cout<<search6<<" "<<search18<<endl;


 }