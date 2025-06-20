#include <iostream>
using namespace std;

class heap {
public:
    int arr[100];
    int index;

    heap() {
        arr[0] = -1; // Placeholder for 1-based indexing
        index = 0;   // Heap starts empty
    }

    void insert(int val) {
        index++;
        arr[index] = val;
        int currentIndex = index;

        while (currentIndex > 1) {
            int parent = currentIndex / 2;
            if (arr[parent] < arr[currentIndex]) {
                swap(arr[parent], arr[currentIndex]);
                currentIndex = parent;
            } else {
                break;
            }
        }
    }

    void print() {
        for (int i = 1; i <= index; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteFromHeap() {
        if (index == 0) {
            return;
        }
        arr[1] = arr[index];
        index--;

        int currentIndex = 1;
        while (currentIndex <= index) {
            int left_child = 2 * currentIndex;
            int right_child = 2 * currentIndex + 1;
            int largest = currentIndex;

            if (left_child <= index && arr[left_child] > arr[largest]) {
                largest = left_child;
            }
            if (right_child <= index && arr[right_child] > arr[largest]) {
                largest = right_child;
            }

            if (largest != currentIndex) {
                swap(arr[currentIndex], arr[largest]);
                currentIndex = largest;
            } else {
                break;
            }
        }
    }
};

void heapify(int arr[], int size, int i) {
    int largest = i;
    int left_child = 2 * i;
    int right_child = 2 * i + 1;

    if (left_child <= size && arr[left_child] > arr[largest]) {
        largest = left_child;
    }
    if (right_child <= size && arr[right_child] > arr[largest]) {
        largest = right_child;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void sort(int arr[], int n) {
    while (n > 1) {
        swap(arr[1], arr[n]);
        n--;
        heapify(arr, n, 1);
    }
}

int main() {
    // Testing heap operations
    heap h;
    h.insert(10);
    h.insert(2);
    h.insert(66);
    h.insert(5);
    h.insert(11);
    cout << "Heap after insertions: ";
    h.print();

    h.deleteFromHeap();
    cout << "Heap after deletion: ";
    h.print();

    // Testing heapify and sort
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    cout << "Array before heapify: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = n / 2; i > 0; i--) {
        heapify(arr, n, i);
    }

    cout << "Max heap: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    sort(arr, n);

    cout << "Sorted array: ";
    for (int i = 1; i <= 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
