//shortest path in undirected graph with unit weights
#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
#include<climits>
using namespace std;
class graph{
    public:
    unordered_map<int,list<int>>mp;

    void addEdge(int u,int v){
        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    void print(){
        for(auto i: mp){
            cout<<i.first<<"->";
            for(auto j : i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

    vector<int> dis (int src){
        queue<pair<int,int>>q; //node,distances
        vector<int>distances(mp.size(),INT_MAX);
        q.push({src,0});
        distances[src] = 0;

        while(!q.empty()){
            pair<int,int>p = q.front();
            q.pop();
            for(auto neighbours : mp[p.first]){
                if(p.second+1 < distances[neighbours]){
                    q.push({neighbours,p.second+1});
                    distances[neighbours] = p.second+1;
                }
            }
        }

        for(auto &i: distances){
            if(i==INT_MAX){
                i = -1;
            }
        }
        return distances;
    }
};
int main(){
    graph g;
    int m;
    cin>>m;
    for(int i = 0;i<m;i++){
        int u, v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    g.print();
    vector<int> answer = g.dis(0);

    for(auto i:answer){
        cout<<i<<" ";
    }
}