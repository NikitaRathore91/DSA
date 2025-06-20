#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    
//   1   // unordered set

unordered_set<int>uset;
//insertion
uset.insert(10);
uset.insert(20);
// check if element exist
if(uset.find(10)!=uset.end()){
    cout<<" Element found "<<endl;
}
else{
    cout<<" Element not found "<<endl;
}
//erase
uset.erase(10);
//iterate thru set
for(int val : uset){
    cout<<val<<" ";
}

//    2    //  vector

}