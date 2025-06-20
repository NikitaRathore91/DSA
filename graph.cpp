#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
class graph{
    public:
    unordered_map<int, list<int> > g;

    void addEdge(int u, int v, bool direction){
        g[u].push_back(v);
        if( direction == 0){
            g[v].push_back(u);
        }

    }

    void print(){
        for(auto i: g){
            cout<<i.first<<"->";
            for(auto j: i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

 
};
int main(){
    int n,m;
    cout<<"enter the number of nodes ->";
    cin>>n;
    cout<<"enter the number of edge ->";
    cin>>m;
    graph gp;
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        gp.addEdge(u,v,0);

    }

    gp.print();
    return 0;
}
