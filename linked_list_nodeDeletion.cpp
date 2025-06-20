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

void deleteNode(node*& root, int target) {
    // If the list is empty, do nothing
    if (root == NULL) return;

    // If the node to delete is the head node
    if (root->data == target) {
        node* toDelete = root;    // Store the current head for deletion
        root = root->next;        // Move head to the next node
        delete(toDelete);         // Delete old head
        return;
    }

    node* temp = root;

    // Traverse the list to find the node whose next has the target value
    // This avoids needing a "previous" pointer
    while (temp->next != NULL && temp->next->data != target) {
        temp = temp->next;
    }

    // If target was not found (end of list), do nothing
    if (temp->next == NULL) return;

    // temp->next is the node to delete
    node* toDelete = temp->next;
    temp->next = temp->next->next;  // Bypass the node to be deleted
    delete(toDelete);               // Free the memory
}

void print(node*root){
    node*temp = root;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main() {

    node* root = new node(5);
    root->next = new node(10);
    root->next->next = new node(15);
    root->next->next->next = new node(20);
    root->next->next->next->next = new node(25);
    

    print(root);

    return 0;
}
