#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

// Definition of a binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Step 1: Create a mapping of parent nodes for each node
void mapParents(Node* root, unordered_map<Node*, Node*>& parentMap) {
    queue<Node*> q;
    q.push(root);
    parentMap[root] = NULL;

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current->left) {
            parentMap[current->left] = current;
            q.push(current->left);
        }
        if (current->right) {
            parentMap[current->right] = current;
            q.push(current->right);
        }
    }
}

// Step 2: Perform BFS to calculate the minimum time
int burnTree(Node* target, unordered_map<Node*, Node*>& parentMap) {
    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    q.push(target);
    visited[target] = true;

    int time = 0;
    while (!q.empty()) {
        int size = q.size();
        bool newNodeBurnt = false;

        for (int i = 0; i < size; i++) {
            Node* current = q.front();
            q.pop();

            // Traverse left child
            if (current->left && !visited[current->left]) {
                visited[current->left] = true;
                q.push(current->left);
                newNodeBurnt = true;
            }

            // Traverse right child
            if (current->right && !visited[current->right]) {
                visited[current->right] = true;
                q.push(current->right);
                newNodeBurnt = true;
            }

            // Traverse parent node
            if (parentMap[current] && !visited[parentMap[current]]) {
                visited[parentMap[current]] = true;
                q.push(parentMap[current]);
                newNodeBurnt = true;
            }
        }

        if (newNodeBurnt) {
            time++;
        }
    }
    return time;
}

// Main function to calculate the minimum time to burn the tree
int minTimeToBurn(Node* root, Node* target) {
    unordered_map<Node*, Node*> parentMap;

    // Step 1: Map parent pointers for each node
    mapParents(root, parentMap);

    // Step 2: Perform BFS from the target node
    return burnTree(target, parentMap);
}

// Helper function to find a node by its value
Node* findNode(Node* root, int targetValue) {
    if (!root) return NULL;
    if (root->data == targetValue) return root;

    Node* leftResult = findNode(root->left, targetValue);
    if (leftResult) return leftResult;

    return findNode(root->right, targetValue);
}

// Driver code
int main() {
    // Build the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);

    int targetValue = 5;
    Node* target = findNode(root, targetValue);

    if (target) {
        cout << "Minimum time to burn the tree: " << minTimeToBurn(root, target) << endl;
    } else {
        cout << "Target node not found in the tree." << endl;
    }

    return 0;
}
