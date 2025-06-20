#include <iostream>
using namespace std;

bool search(int arr[], int n, int key) {
    if (n == 0) {
        return false; // Base case: key not found
    }
    
    if (arr[0] == key) {
        return true; // Key found in the current element
    }
    
    // Recursively search in the rest of the array
    return search(arr + 1, n - 1, key);
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int key = 4;
    if (search(arr, 5, key)) {
        cout << "Found\n";
    } else {
        cout << "Not found\n";
    }
    return 0;
}