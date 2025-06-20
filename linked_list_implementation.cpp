#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;

    node(int d){
        data = d;
        next = NULL;
    }
};
void insertAtTail(node*&root,int d){
    node*temp = root;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new node(d);
}
void print(node*root){
    node*temp = root;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
bool search(node*root,int target){
    if(root==NULL) return false;
    node*temp = root;
    while(temp!=NULL){
        if(temp->data==target) return true;
        temp = temp->next;
    }
    return false;
}
void insertAtHead(node*&root,int d){
    node*temp = new node(d);
    temp->next = root;
    root = temp;
}
int main(){
    node*root = new node(5);
    root->next = new node(10);
    root->next->next = new node(15);
    root->next->next->next = new node(20);
    insertAtTail(root,25);
    insertAtHead(root,0);
    print(root);



}