#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adj;

    // Add edge from u to v (directed)
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Kahn's Algorithm to detect cycle using BFS
    bool Topo_bfs(vector<int>& indegree) {
        queue<int> q;

        // Push all nodes with indegree 0 into the queue
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;  // Count of processed nodes

        while (!q.empty()) {
            int front = q.front();
            q.pop();
            count++;

            // Decrease indegree of neighboring nodes
            for (auto neighbour : adj[front]) {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        // If count != number of nodes, there's a cycle
        return count != indegree.size();
    }
};

int main() {
    int n, m;
    cin >> n >> m;  // n = number of nodes, m = number of edges

    Graph g;


    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;  // Edge from u to v
        g.addEdge(u, v);
    }

 

    return 0;
}
