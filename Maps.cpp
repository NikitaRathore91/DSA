#include <bits/stdc++.h>
using namespace std;
int main(){
    map<int,string>m;
    m[1]="abc";
    m[3]="def";
    m[5]="ghi";
    m.insert({0,"jkl"});
    m.insert({7,"mno"});
    map<int,string>::iterator it;
    for(it =m.begin();it!=m.end();it++){
        cout<<(*it).first<<" "<<it->second<<endl;
    }
    cout<<endl;
    cout<<endl;
    //another way to print
    for(auto &abc :m){
        cout<<abc.first<<" "<<abc.second<<endl;
    }
    cout<<endl;

    //size of map //
    cout<<"size of the map is "<<m.size()<<endl;

    //FIND//
    //this returns an iterator//
     auto ab = m.find(7);
     if(ab==m.end()){
        cout<<"No value found! "<<endl;
     }
     else{
        cout<<"Value found-> ";
        cout<<ab->first<<" "<<ab->second<<endl;
        //alternate way-> cout<<(*ab).first<<" "<<(*ab).second<<endl;
     }


     //ERASE//
    m.erase(1);
    for(auto ab :m){
        cout<<ab.first<<" "<<ab.second<<endl;
    }

    //ClEAR ->m.clear();  this will clear the whole map //
}