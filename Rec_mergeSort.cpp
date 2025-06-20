// isme er are making duplicate arrays wapas jate waqt aur jb humne mid partition krke array ko do mai divide kiya 
// toh hum dono k forst elememt ko compare krke original array mai sort kr rhe hai
// jaise {3,2,5,1} sbse phle mergeSort call hua
//                    mergeSort({3, 2, 5, 1}, 0, 3)
//                                 /                 \
//                  mergeSort({3, 2}, 0, 1)                 mergeSort({5, 1}, 2, 3)
//                     /         \                                  /         \
//          mergeSort({3}, 0, 0)  mergeSort({2}, 1, 1)     mergeSort({5}, 2, 2) mergeSort({1}, 3, 3)
// and an merge call hoga jisme (arr,0,1) pass hoga yeh dono k first elelments compare honge 
// fir original array mai sorted hoke jayeg

#include<iostream>
using namespace std;

void merge(int* arr, int s, int e) {
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int* first = new int[len1];
    int* second = new int[len2];

    int k = s;
    for (int i = 0; i < len1; i++) {
        first[i] = arr[k++];
    }
    k = mid + 1;
    for (int i = 0; i < len2; i++) {
        second[i] = arr[k++];
    }

    int i = 0, j = 0;
    k = s;

    while (i < len1 && j < len2) {
        if (first[i] <= second[j]) {
            arr[k++] = first[i++];
        } else {
            arr[k++] = second[j++];
        }
    }

    while (i < len1) {
        arr[k++] = first[i++];
    }

    while (j < len2) {
        arr[k++] = second[j++];
    }

    delete[] first;
    delete[] second;
}

void mergeSort(int* arr, int s, int e) {
    if (s >= e) {
        return;
    }
    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}

int main() {
    int arr[] = {4, 1, 3, 9, 2, 6};
    int s = 0;
    int e = sizeof(arr) / sizeof(arr[0]) - 1;

    cout << "Original array: ";
    for (int i = 0; i <= e; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, s, e);

    cout << "Sorted array: ";
    for (int i = 0; i <= e; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}