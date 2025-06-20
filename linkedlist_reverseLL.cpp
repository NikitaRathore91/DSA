#include <iostream>
#include <vector>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int d) {
        data = d;
        next = NULL;
    }
};


void print(node*root){
    node*temp = root;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
//the following function prints a reverse of LL without reversing it with the help of recursion
void printReverse(node*root){
    if(root==NULL) return;
    printReverse(root->next);
    cout<< root->data<<" ";
}
// the  following function actually reverses it
node* reverse(node*&root){
   node*curr = root;
   node*prev = NULL;
   
   while(curr!=NULL){
    node*post = curr->next;
    curr->next = prev;

    prev = curr;
    curr = post; 
   } 

   node*new_root = prev;
   return new_root;
}
int main(){
    node*root =  new node(1);
    root->next = new node(2);
    root->next->next = new node(2);
    root->next->next->next = new node(2);
    root->next->next->next->next = new node(3);
    root->next->next->next->next->next = new node(3);
    root->next->next->next->next->next->next = new node(3);
    root->next->next->next->next->next->next->next = new node(3);
    root->next->next->next->next->next->next->next->next = new node(4);
    // 1 2 2 2 3 3 3 3 4
    print(root);
    cout<<endl;
    //printReverse(root);
    node*abc = reverse(root);
    print(abc);

}