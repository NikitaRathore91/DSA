#include<iostream>
#include<climits>
#include<unordered_map>
#include<list>
#include<set>
#include<vector>

using namespace std;

class graph {
public:
    unordered_map<int, list<pair<int, int>>> mp;

    void addEdge(int u, int v, int distance, bool direction) {
        mp[u].push_back({v, distance});
        if (direction == 0) {
            mp[v].push_back({u, distance});
        }
    }

    void print() {
        for (auto i : mp) {
            cout << i.first << "->";
            for (auto j : i.second) {
                cout << "{" << j.first << "," << j.second << "} ";
            }
            cout << endl;
        }
    }

    vector<int> dis(int src) {
        vector<int> distances(mp.size(), INT_MAX);
        set<pair<int, int>> st; // {distance, node}
        
        distances[src] = 0;
        st.insert({0, src});

        while (!st.empty()) {
            auto top = *(st.begin());
            st.erase(st.begin());

            int nodeDist = top.first;
            int node = top.second;

            for (auto neighbour : mp[node]) {
                int adjNode = neighbour.first;
                int edgeWeight = neighbour.second;

                if (nodeDist + edgeWeight < distances[adjNode]) {
                    // If already in set, remove the older entry
                    if (distances[adjNode] != INT_MAX) {
                        st.erase({distances[adjNode], adjNode});
                    }

                    // Update distance and insert new pair
                    distances[adjNode] = nodeDist + edgeWeight;
                    st.insert({distances[adjNode], adjNode});
                }
            }
        }

        for (auto &i : distances) {
            if (i == INT_MAX) {
                i = -1;
            }
        }

        return distances;
    }
};

int main() {
    int m;
    cin >> m;
    graph g;
    for (int i = 0; i < m; i++) {
        int v, u, distance;
        cin >> v >> u >> distance;
        g.addEdge(u, v, distance, 0);
    }

    g.print();
    vector<int> answer = g.dis(0);

    for (auto i : answer) {
        cout << i << " ";
    }

    return 0;
}