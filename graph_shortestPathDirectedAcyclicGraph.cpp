#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
using namespace std;
class graph{
    public:
    unordered_map<int,list<pair<int,int>>> mp;

    void addEdge(int u,int v,int distance){
        //this is acyclic graph-> no need to add direction
        mp[u].push_back({v,distance});
    }

    void print(){
        for(auto i:mp){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<"{"<<j.first<<","<<j.second<<"}"<<" ";
            }
            cout<<endl;
        }
    }
    void dfs_topo(int node,unordered_map<int,bool>&visited,stack<int>&s){
        visited[node] = true;

        for(auto neighbours: mp[node]){
            if(!visited[neighbours.first]){
                dfs_topo(neighbours.first,visited,s);
            }
        }

        s.push(node);
    }
    void dfs_topo_helper(stack<int>&s){
        unordered_map<int,bool>visited;
        //stack<int>s;
        for(auto& pair : mp){
           if(!visited[pair.first]){
              dfs_topo(pair.first, visited, s);
        }
      }
    }

    vector<int> find_minimum_dis(stack<int>&s,int src){
        vector<int>distance(mp.size(),INT_MAX);
        distance[src] = 0;
        while(!s.empty()){
            int node = s.top();
            s.pop();
            for(auto neighbours: mp[node]){
                if(distance[node]+neighbours.second < distance[neighbours.first]){
                    distance[neighbours.first] = distance[node]+neighbours.second;
                }
            }
        }

        return distance;
    }

};
int main(){
    graph g;
    int m;  //edges
    cin>>m;

    for(int i = 0;i<m;i++){
        int u,v,distance;
        cin>>u>>v>>distance;
        g.addEdge(u,v,distance);
    }
    //g.print();

    stack<int>s;
    g.dfs_topo_helper(s);
    vector<int>answer = g.find_minimum_dis(s,0);

    for(auto j:answer){
        cout<<j<<" ";
    }

}