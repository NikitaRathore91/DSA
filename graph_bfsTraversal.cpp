#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

class graph {
public:
    unordered_map<int, list<int>> mp;

    void addEdge(int u, int v, bool direction) {
        if (direction == 1) {
            mp[u].push_back(v);
        } else {
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
    }

    void print() {
        for (auto i : mp) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void bfsHelper(int start, unordered_map<int, bool> &visited) {
        queue<int> q;
        q.push(start);
        visited[start] = true;
    
        while (!q.empty()) {
            int fr = q.front();
            q.pop();
            cout << fr << " ";
    
            for (auto neighbor : mp[fr]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
    
    void bfs() {
        unordered_map<int, bool> visited;
    
        for (auto node : mp) { // Handling disconnected components
            if (!visited[node.first]) {
                cout << "Component: ";
                bfsHelper(node.first, visited);
                cout << endl;
            }
        }
    }
    
};

int main() {
    int n, m;
    cin >> n >> m;
    
    // n is total nodes and m is total edges
    graph g;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }
    g.print();

    cout << "BFS Traversal for Disconnected Graph:\n";
    g.bfs();  // Single function handling both connected and disconnected graphs

    return 0;
}