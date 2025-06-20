#include <iostream>
#include <vector>
using namespace std;

void PnC(vector<int> num, int index, int size, vector<vector<int>>& ans) {
    if (index >= size) {
        ans.push_back(num);
        return;
    }
    for (int j = index; j < size; j++) {
        swap(num[index], num[j]);
        PnC(num, index + 1, size, ans);
        swap(num[index], num[j]);  // backtrack
    }
}

int main() {
    vector<int> num = {1, 2, 3};
    int index = 0;
    int size = 3;
    vector<vector<int>> ans;
    PnC(num, index, size, ans);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}