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

// Function to insert a node at the end of the list
void insert(node*& head, int data) {
    if (head == NULL) {
        head = new node(data);
        return;
    }
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new node(data);
}

// Function to print the linked list
void print(node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to merge two sorted linked lists
node* merge(node* l1, node* l2) {
    node dummy(0);
    node* tail = &dummy;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL) tail->next = l1;
    else tail->next = l2;

    return dummy.next;
}

// Function to find the middle node and split the list
node* getMid(node* head) {
    if (head == NULL || head->next == NULL) return head;

    node* slow = head;
    node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    node* mid = slow->next;
    slow->next = NULL;
    return mid;
}

// Recursive Merge Sort function for linked list
node* mergeSort(node* head) {
    if (head == NULL || head->next == NULL) return head;

    node* mid = getMid(head);

    node* left = mergeSort(head);
    node* right = mergeSort(mid);

    return merge(left, right);
}

// Driver function
int main() {
    node* head = NULL;

    vector<int> values = {4, 2, 1, 3, 5};
    for (int val : values) {
        insert(head, val);
    }

    cout << "Original list: ";
    print(head);

    head = mergeSort(head);

    cout << "Sorted list: ";
    print(head);

    return 0;
}
