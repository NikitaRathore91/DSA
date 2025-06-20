//dijktra algo is used to find the shortest path from the src node to all other nodes present. 
//It does not work with negative weights(path) , time complexity:- O(n+m)logn
//min heap-priority queue is used
#include <iostream>
#include <climits>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Graph {
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int distance, bool directed) {
        adj[u].push_back({v, distance});
        if (!directed) {
            adj[v].push_back({u, distance});
        }
    }

    void print() {
        for (auto &node : adj) {
            cout << node.first << " -> ";
            for (auto &neigh : node.second) {
                cout << "{" << neigh.first << "," << neigh.second << "} ";
            }
            cout << endl;
        }
    }

    vector<int> dijkstra(int src) {
        vector<int> dist(adj.size(), INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();

            int currDist = p.first;
            int node = p.second;

            if (currDist > dist[node]) continue;

            for (auto &neigh : adj[node]) {
                int adjNode = neigh.first;
                int distance = neigh.second;

                if (currDist + distance < dist[adjNode]) {
                    dist[adjNode] = currDist + distance;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        for (auto &d : dist) {
            if (d == INT_MAX) d = -1;
        }

        return dist;
    }
};

int main() {
    int m;
    cin >> m;
    Graph g;

    for (int i = 0; i < m; ++i) {
        int u, v, distance;
        cin >> u >> v >> distance;
        g.addEdge(u, v, distance, false); // undirected
    }

    g.print();
    vector<int> result = g.dijkstra(0);

    for (int d : result) {
        cout << d << " ";
    }

    return 0;
}

