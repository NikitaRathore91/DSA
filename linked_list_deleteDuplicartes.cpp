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

void deleteDuplicates(node*&root){
    node*curr = root;
    while(curr!=NULL && curr->next!=NULL){
        if(curr->data==curr->next->data){
            node*temp = curr->next;
            curr->next = curr->next->next;
            temp->next = NULL;
            delete(temp);
        }
        else{
            curr=curr->next;
        }
    }
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
    deleteDuplicates(root);
    print(root);
  

}