#include<iostream>
#include<vector>
#include<map>
#include<list>
using namespace std;
int main(){
    // 1 : range based loops
    // on vector
    vector<int>a = {1,2,3,4,5};
    for(auto element : a){
        cout<<element<<" ";
    }
    cout<<endl;
    vector<int>b ={1,2,3};
    for(auto& element : b){
        element = element*2;
    }
    for(auto element : b){
        cout<<element<<" ";
    }
    cout<<endl;
    // on maps
    map<int,string>mp = {{1,"one"},{2,"two"},{3,"three"}};
    for(auto pair : mp){
        cout<<pair.first<<" "<<pair.second<<endl;
    }

    // map of type map<int,list<int>>
    map<int,list<int> >myMap;
    myMap[1] = {1,2,3};
    myMap[2] = {2,4,6,8};
    myMap[3] = {3,6,9,12,15};

    for(const auto &pair :myMap){
        cout<<pair.first<<"->";
        for(const auto&vall : pair.second){
            cout<<vall<<" ";
        }
        cout<<endl;
    }
    cout<<endl;


    // 2 loop with iterator 
    //on vector
    for(auto it = a.begin(); it!= a.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    // on map
    for(auto it = mp.begin(); it!= mp.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
}