#include<iostream>
using namespace std;

class CircularQueue {
public:
    int front;
    int rear;
    int* arr;
    int size;

    // Constructor to initialize the circular queue
    CircularQueue(int x) {
        size = x;
        front = -1;  // Initialize front and rear to -1 indicating an empty queue
        rear = -1;
        arr = new int[size];
    }

    // Push function to add elements to the circular queue
    void push(int y) {
        if ((rear + 1) % size == front) {  // Check if the queue is full
            cout << "Overflow!! Queue is full." << endl;
        } else {
            // If the queue is empty, set front to 0
            if (front == -1) {
                front = 0;
            }
            rear = (rear + 1) % size;  // Move rear to the next position circularly
            arr[rear] = y;
            cout << y << " added to the queue." << endl;
        }
    }

    // Pop function to remove elements from the circular queue
    void pop() {
        if (front == -1) {  // Check if the queue is empty
            cout << "No element to pop! Queue is empty." << endl;
        } else {
            cout << "Popped element: " << arr[front] << endl;
            if (front == rear) {  // The queue becomes empty after popping the last element
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % size;  // Move front circularly
            }
        }
    }

    // Function to check if the queue is empty
    bool empty() {
        return (front == -1);  // Queue is empty when front is -1
    }

    // Peek function to get the front element
    int peek() {
        if (empty()) {
            cout << "Queue is empty, no element to peek!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Function to check if the queue is full
    bool isFull() {
        return (front == (rear + 1) % size);  // The queue is full if next position of rear is front
    }
};

int main() {
    CircularQueue queue1(5);  // Create a circular queue with size 5

    queue1.pop();  // No element to pop (queue is empty)
    queue1.push(1);
    queue1.push(2);
    queue1.push(3);
    queue1.push(4);
    queue1.push(5);  // This should trigger overflow as the queue is full

    int f = queue1.peek();  // Peek the front element
    if (f != -1) {
        cout << "Front element: " << f << endl;  // Output the front element
    }

    queue1.pop();  // Pop the front element (1)
    queue1.push(6);  // Add 6 to the queue, this will work as it's circular

    cout << "Queue is " << (queue1.empty() ? "empty" : "not empty") << endl;  // Check if the queue is empty
    cout << "Queue is " << (queue1.isFull() ? "full" : "not full") << endl;  // Check if the queue is full

    return 0;
}