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

void delete_alternate(node*& root){
    node*curr = root;
    while(curr!=NULL && curr->next !=NULL ){
        node*temp = curr->next;
        curr->next = curr->next->next;
        temp->next = NULL;
        delete(temp);
        curr =curr->next;
    }
}

void print(node*root){
    node*temp = root;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    node*root =  new node(1);
    root->next = new node(2);
    root->next->next = new node(3);
    root->next->next->next = new node(4);
    root->next->next->next->next = new node(5);
    root->next->next->next->next->next = new node(6);
    print(root);
    cout<<endl;
    delete_alternate(root);
    print(root);

}