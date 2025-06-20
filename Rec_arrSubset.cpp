#include<iostream>
#include<vector>
using namespace std;

void solve(int *arr, vector<int> output, int index, vector<vector<int>>& ans, int size) {
    if (index >= size) {
        ans.push_back(output);
        return;
    }

    // Exclude the current element
    solve(arr, output, index + 1, ans, size);

    // Include the current element
    int num = arr[index];
    output.push_back(num);
    solve(arr, output, index + 1, ans, size);
}

int main() {
    int arr[3] = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    int size = sizeof(arr) / sizeof(arr[0]);  
    solve(arr, output, index, ans, size);

    for (const auto& v : ans) {
        cout << "{ ";
        for (int x : v) {
            cout << x << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}