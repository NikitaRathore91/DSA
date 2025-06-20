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
    void topoSort(int node,unordered_map<int,bool>&visited,stack<int>&s){
        visited[node] = true;
        for(auto neighbour :mp[node]){
            if(!visited[neighbour]){
                topoSort(neighbour,visited,s);
            }
        }
        s.push(node);
    }
    void topoSort_helper(){
        unordered_map<int,bool>visited;
        stack<int>s;
        for(auto i: mp){
            if(!visited[i.first]){
                topoSort(i.first,visited,s);
            }
        }

        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
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

    g.topoSort_helper();
}
