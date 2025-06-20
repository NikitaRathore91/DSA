#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class graph {
public:
    unordered_map<int, list<int>> mp;

    void addEdge(int u, int v, bool direction) {
        mp[u].push_back(v);
        if (direction == 0) {
            mp[v].push_back(u);
        }
    }

    void print() {
        for (auto i : mp) {
            cout << i.first << "->";
            for (auto j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    bool cycleDFS(int node, int parent, unordered_map<int, bool>& visited) {
        visited[node] = true;

        for (auto neighbour : mp[node]) {
            if (!visited[neighbour]) {
                if (cycleDFS(neighbour, node, visited)) {
                    return true;
                }
            } else if (neighbour != parent) {
                return true; // Found a back edge, meaning a cycle exists.
            }
        }
        return false;
    }

    bool is_cycle() {
        unordered_map<int, bool> visited;
        for (auto node : mp) {
            if (!visited[node.first]) {
                if (cycleDFS(node.first, -1, visited)) {
                    return true;
                }
            }
        }
        return false;
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

    bool detectcycle = g.is_cycle(); 
    cout << detectcycle;
    return 0;
}
