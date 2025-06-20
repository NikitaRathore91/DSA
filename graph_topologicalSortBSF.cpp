//kahn's algorithm
#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction) {
        adj[u].push_back(v);
        if (direction == 0) { // If the graph is undirected
            adj[v].push_back(u);
        }
    }

    void bfs(vector<int>& indegree) {  // Kahn's Algorithm
        queue<int> q;

        // Push all nodes with indegree 0
        for (int i = 1; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            int fr = q.front();
            q.pop();
            ans.push_back(fr);

            for (auto neighbour : adj[fr]) {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        // Print topological order
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph g;
    vector<int> indegree(n + 1, 0);  // Correctly sized in-degree array

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 1);  // Directed graph
        indegree[v]++;       // Increase in-degree of the destination node
    }

    g.bfs(indegree);
    return 0;
}
