#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int>& myStack, int value) {
    if (myStack.empty()) {
        myStack.push(value);
        return;
    }

    // Recursively pop all elements and insert the value at the bottom
    int topElement = myStack.top();
    myStack.pop();
    insertAtBottom(myStack, value);
    myStack.push(topElement);
}

// Function to reverse the stack
void reverseStack(stack<int>& myStack) {
    if (myStack.empty()) {
        return;
    }

    // Recursively pop all elements and insert them at the bottom in reverse order
    int topElement = myStack.top();
    myStack.pop();
    reverseStack(myStack);
    insertAtBottom(myStack, topElement);
}

int main() {
    stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);

    cout << "Stack elements before reversal (from top to bottom): ";
    stack<int> tempStack1 = myStack; // Create a temporary stack to print elements without modifying the original stack
    while (!tempStack1.empty()) {
        cout << tempStack1.top() << " ";
        tempStack1.pop();
    }
    cout << endl;

    reverseStack(myStack);

    // Print stack elements after reversal
    cout << "Stack elements after reversal (from top to bottom): ";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    return 0;
}