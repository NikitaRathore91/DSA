#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>

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

    void dfs(int node,unordered_map<int,bool>&visited){
        cout<<node<<" ";
        for(auto neighbour : mp[node]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                dfs(neighbour,visited);
            }
        }
    }

    void dfs_helper(){
        unordered_map<int,bool>visited;
        for(auto node:mp){
            if(!visited[node.first]){
                visited[node.first] = true;
                dfs(node.first,visited);
                cout<<endl;
            }
        }
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

    cout << "DFS Traversal for Disconnected Graph:\n";
    g.dfs_helper();

    return 0;
}
