#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node*prev;

    node(int d){
        data = d;
        next = NULL;
        prev = NULL;
    }
};
//1)Insert_at_tail   2)Insert_at_head  3)insert_at_middle  4)Print   5)Delete_node
void insertAtTail(node*&root,int d){
    if(root==NULL){
        root = new node(d);
        return;
    }
    node*temp = root;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = new node(d);
    temp->next->prev = temp;

}

void insertAtHead(node*&root,int d){
    node*temp = new node(d);
    if(root!=NULL){
        temp->next = root;
        root->prev = temp;
    }
    root = temp;
}

void insertAtPosition(node*&root,int k,int d){
    if(root==NULL) return;
    // k ->position
    if(k==1){
        insertAtHead(root,d);
        return;
    }

    int count = 1;
    node*temp = root;

    while(count<k-1 && temp!=NULL){
       
            temp = temp->next;
            count++;
        
    }

    if(temp==NULL) return;

    node*post = temp->next;
    node*toInsert = new node(d);

    temp->next = toInsert;
    toInsert->next = post;
    toInsert->prev = temp;
    if(post!=NULL){
        post->prev = toInsert;
    }

}

void print(node*root){
    if(root==NULL) return;
    node*temp = root;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void DeleteNode(node*& root, int position) {
    if(root == NULL || position <= 0) return;

    if(position == 1) {
        node* toDelete = root;
        root = root->next;
        if(root != NULL) root->prev = NULL;
        delete toDelete;
        return;
    }

    int count = 1;
    node* temp = root;
    while(count < position - 1 && temp != NULL){
        temp = temp->next;
        count++;
    }

    if(temp == NULL || temp->next == NULL) return;

    node* toDelete = temp->next;
    temp->next = toDelete->next;

    if(temp->next != NULL) {
        temp->next->prev = temp;
    }

    delete toDelete;
}


int main(){
    node*root = NULL;
    insertAtTail(root,5);
    insertAtTail(root,10);
    insertAtTail(root,15);
    insertAtTail(root,20);
    insertAtPosition(root,3,12);
    print(root);

}