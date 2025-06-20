#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
void find(vector<int>a,int value){
    auto it = find(a.begin(),a.end(),value);

    if(it!=a.end()){
        int index  = it-a.begin();
        cout<<index;
    }
    else{
        cout<<-1;
    }
}
int main(){
vector<int>a({1,2,3,4,5,1});
int value = 1;
find(a,value);
}