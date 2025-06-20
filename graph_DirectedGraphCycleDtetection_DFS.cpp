#include <iostream>
#include <queue>
#include<stack>
#include<unordered_map>
#include<list>
using namespace std;
class graph{
    public:
    unordered_map<int,list<int>>mp;

    void addEdge(int u,int v,bool direction){
        mp[u].push_back(v);
        if(direction==0){
            mp[v].push_back(u);
        }
    }
    bool detectdirectedGraphCycle(int node, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsVisitef) {
        visited[node] = true;
        dfsVisitef[node] = true;  // mark the node in the recursion stack
    
        for (auto neighbour : mp[node]) {
            if (!visited[neighbour]) {
                if (detectdirectedGraphCycle(neighbour, visited, dfsVisitef)) {
                    return true;
                }
            } else if (dfsVisitef[neighbour]) {
                return true; // back edge found → cycle
            }
        }
    
        dfsVisitef[node] = false;  // backtracking
        return false;
    }
    
    bool cycle_helper() {
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsVisitef;
    
        for (auto i : mp) {
            if (!visited[i.first]) {
                if (detectdirectedGraphCycle(i.first, visited, dfsVisitef)) {
                    return true;
                }
            }
        }
        return false;
    }
    
};
int main() {
    int m;
    cin>>m;
    graph g;
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,1);
    }

    cout<<g.cycle_helper();

}