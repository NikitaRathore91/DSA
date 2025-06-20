#include <iostream>
using namespace std;

int partition(int* arr, int s, int e) {
    int pivot = arr[s]; // Choose the first element as pivot
    int cnt = 0;

    // Count how many elements are less than the pivot
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] < pivot) {
            cnt++;
        }
    }

    // Place the pivot in its correct position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    //chote element ko left mai dalo aur bad ko right mai
    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int* arr, int s, int e) {
    if (s >= e) {
        return;
    }

    int p = partition(arr, s, e);
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main() {
    int arr[] = {2, 8, 5, 0, 7, 3, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
