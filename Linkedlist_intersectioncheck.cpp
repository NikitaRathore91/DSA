#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int x) {
        data = x;
        next = NULL;
    }
};

void insertathead(node*& head, int y) {
    node* temp = new node(y);
    temp->next = head;
    head = temp;
}

void insertattail(node*& head, int y) {
    if (head == NULL) {
        insertathead(head, y);
        return;
    }
    node* temp = new node(y);
    node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = temp;
}

void print(node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int getlength(node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

void getintersection(node* head1, node* head2) {
    int l1 = getlength(head1);
    int l2 = getlength(head2);

    node* ptr1 = head1;
    node* ptr2 = head2;

    if (l1 > l2) {
        for (int i = 0; i < l1 - l2; i++) {
            ptr1 = ptr1->next;
        }
    } else {
        for (int i = 0; i < l2 - l1; i++) {
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2) {
            cout << "Yes, intersection is here at node with data: " << ptr1->data << endl;
            return;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    cout << "No intersection found" << endl;
}

int main() {
    node* node1 = new node(1);
    node* head1 = node1;
    node* node2 = new node(6);
    node* head2 = node2;

    insertattail(head1, 2);
    insertattail(head1, 3);
    insertattail(head1, 4);
    insertattail(head1, 5);

    insertattail(head2, 7);
    // Creating an intersection
    head2->next->next = head1->next->next;

    getintersection(head1, head2);

    return 0;
}