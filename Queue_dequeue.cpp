#include<iostream>
using namespace std;

class Deque {
    int* arr;   // Array to store the deque elements
    int front;  // Points to the front element in the deque
    int rear;   // Points to the rear element in the deque
    int size;   // Maximum size of the deque

public:
    // Constructor to initialize the deque
    Deque(int x) {
        size = x;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Check if the deque is full
    bool isFull() {
        return ((front == 0 && rear == size - 1) || (front == rear + 1));
    }

    // Check if the deque is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Insert an element at the front of the deque
    void insertFront(int x) {
        if (isFull()) {
            cout << "Overflow! Cannot insert at front." << endl;
            return;
        }

        // If the deque is initially empty
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = size - 1;  // Circularly move to the last position
        } else {
            front--;  // Move front backward
        }

        arr[front] = x;
        cout << x << " inserted at the front." << endl;
    }

    // Insert an element at the rear of the deque
    void insertRear(int x) {
        if (isFull()) {
            cout << "Overflow! Cannot insert at rear." << endl;
            return;
        }

        // If the deque is initially empty
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == size - 1) {
            rear = 0;  // Circularly move to the first position
        } else {
            rear++;  // Move rear forward
        }

        arr[rear] = x;
        cout << x << " inserted at the rear." << endl;
    }

    // Delete an element from the front of the deque
    void deleteFront() {
        if (isEmpty()) {
            cout << "Underflow! No element to delete from front." << endl;
            return;
        }

        cout << "Deleted element: " << arr[front] << " from front." << endl;

        // If deque has only one element
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == size - 1) {
            front = 0;  // Circularly move to the first position
        } else {
            front++;  // Move front forward
        }
    }

    // Delete an element from the rear of the deque
    void deleteRear() {
        if (isEmpty()) {
            cout << "Underflow! No element to delete from rear." << endl;
            return;
        }

        cout << "Deleted element: " << arr[rear] << " from rear." << endl;

        // If deque has only one element
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            rear = size - 1;  // Circularly move to the last position
        } else {
            rear--;  // Move rear backward
        }
    }

    // Get the front element of the deque
    int getFront() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Get the rear element of the deque
    int getRear() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        return arr[rear];
    }
};

// Main function to demonstrate the operations
int main() {
    Deque dq(5);  // Create a deque with size 5

    dq.insertRear(5);
    dq.insertRear(10);
    dq.insertFront(3);
    dq.insertFront(1);
    
    cout << "Front element: " << dq.getFront() << endl;  // Output: 1
    cout << "Rear element: " << dq.getRear() << endl;    // Output: 10
    
    dq.deleteFront();  // Remove front element (1)
    dq.deleteRear();   // Remove rear element (10)

    cout << "Front element after deletion: " << dq.getFront() << endl;  // Output: 3
    cout << "Rear element after deletion: " << dq.getRear() << endl;    // Output: 5

    return 0;
}