#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
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
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    bool check(unordered_map<int, bool>& visited, int src) {
        queue<int> q;
        unordered_map<int, int> parent;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty()) {
            int fr = q.front();
            q.pop();
            
            for (auto neighbour : mp[fr]) {
                // If the node is already visited and is **not** the parent, it's a cycle
                if (visited[neighbour] && parent[fr] != neighbour) {
                    return true;
                }

                if (!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = fr;
                }
            }
        }
        return false;
    }

    bool isCycle() {
        unordered_map<int, bool> visited;
        
        for (auto node : mp) {
            if (!visited[node.first]) {
                if (check(visited, node.first)) {
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

    graph g;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }
    
    g.print();

    bool isitcycle = g.isCycle();
    cout << isitcycle;

    return 0;
}
#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
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
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    bool check(unordered_map<int, bool>& visited, int src) {
        queue<int> q;
        unordered_map<int, int> parent;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty()) {
            int fr = q.front();
            q.pop();
            
            for (auto neighbour : mp[fr]) {
                // If the node is already visited and is **not** the parent, it's a cycle
                if (visited[neighbour] && parent[fr] != neighbour) {
                    return true;
                }

                if (!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = fr;
                }
            }
        }
        return false;
    }

    bool isCycle() {
        unordered_map<int, bool> visited;
        
        for (auto node : mp) {
            if (!visited[node.first]) {
                if (check(visited, node.first)) {
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

    graph g;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }
    
    g.print();

    bool isitcycle = g.isCycle();
    cout << isitcycle;

    return 0;
}
