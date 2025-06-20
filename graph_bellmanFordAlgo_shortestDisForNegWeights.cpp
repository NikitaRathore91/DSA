#include <iostream>
#include <climits>
#include <vector>

#define ll long long
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(m, vector<int>(3));
    vector<ll> dis(n, INT_MAX);  // Okay, as long as we check properly
    dis[0] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[i][0] = u;
        graph[i][1] = v;
        graph[i][2] = weight;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = graph[j][0];
            int v = graph[j][1];
            int weight = graph[j][2];

            // ✅ Prevent overflow
            if (dis[u] != INT_MAX && dis[u] + weight < dis[v]) {
                dis[v] = dis[u] + weight;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dis[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dis[i] << " ";
    }

    return 0;
}
