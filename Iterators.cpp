//Iterators are used to access and iterate through elements of data structures (vectors, sets, etc.), by "pointing" to them.
//It is called an "iterator" because "iterating" is the technical term for looping.

/*      begin() returns an iterator that points to the first element of the data structure.

        end() returns an iterator that points to one position after the last element.
        */
#include <bits/stdc++.h>
using namespace std;
int main(){
    //use of iterator in maps
    unordered_map<string,int>om;
    om["abc"]=0;
    om["abc1"]=1;
    om["abc2"]=2;
    om["abc3"]=3;

    unordered_map<string,int>::iterator it =om.begin();
    while(it!=om.end()){
        cout<<"Key is -> "<<it->first<<" Value is -> "<<it->second<<endl;
        it++;
    }

    //use of iterator in vectors
    vector<int>v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vector<int>:: iterator it1 = v.begin();

    for(it1=v.begin();it1<v.end();it1++){
        cout<<*it1<<" ";
    }
    cout<<endl;
    //find
    //unordered_map<string,int>::iterator it2 = om.find("abc");
    
    //erase
    // om.erase(it2,it2+3);
    // om.erase(it1);
    
}