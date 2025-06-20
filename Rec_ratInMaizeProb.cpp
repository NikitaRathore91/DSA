#include <iostream>
#include <vector>
using namespace std;

bool isPossible(int x, int y, int mat[][10], int visited[][10], int m) {
    if (x >= 0 && x < m && y >= 0 && y < m && mat[x][y] == 1 && visited[x][y] == 0) {
        return true;
    }
    return false;
}

void solve(int mat[][10], int visited[][10], int x, int y, vector<string>& ans, string path, int m) {
    if (x == m - 1 && y == m - 1) {
        ans.push_back(path);
        return;
    }

    // Mark the current cell as visited
    visited[x][y] = 1;

    // Downward movement
    if (isPossible(x + 1, y, mat, visited, m)) {
        solve(mat, visited, x + 1, y, ans, path + 'D', m);
    }

    // Rightward movement
    if (isPossible(x, y + 1, mat, visited, m)) {
        solve(mat, visited, x, y + 1, ans, path + 'R', m);
    }

    // Leftward movement
    if (isPossible(x, y - 1, mat, visited, m)) {
        solve(mat, visited, x, y - 1, ans, path + 'L', m);
    }

    // Upward movement
    if (isPossible(x - 1, y, mat, visited, m)) {
        solve(mat, visited, x - 1, y, ans, path + 'U', m);
    }

    // Unmark the current cell as visited for backtracking
    visited[x][y] = 0;
}

int main() {
    int m;
    cin >> m;

    int mat[10][10];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    int visited[10][10] = {0};

    vector<string> ans;
    string path = "";

    // If the starting cell is not blocked, start the pathfinding
    if (mat[0][0] == 1) {
        solve(mat, visited, 0, 0, ans, path, m);
    }

    if (ans.empty()) {
        cout << -1 << endl;
    } else {
        for (string p : ans) {
            cout << p << " ";
        }
        cout << endl;
    }

    return 0;
}
