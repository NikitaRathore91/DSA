#include<iostream>
#include<deque>
#include<queue>
using namespace std;
int main(){
 deque<int>dq;
 dq.push_back(1);
 dq.push_back(2);
 dq.push_front(10);
 dq.push_front(20);

 cout<<dq.size()<<endl;
 while(!dq.empty()){
   cout<<dq.front()<<" ";
   dq.pop_front();
 }

}