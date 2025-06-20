#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main(){
  queue<int>q;
  stack<int>s;
  q.push(1);
  q.push(3);
  q.push(5);
  q.push(7);
  q.push(9);
  q.push(11);

  queue<int>clone =q;
 //initial print
  while(!clone.empty()){
    cout<<clone.front()<<" ";
    clone.pop();
  }
  cout<<endl;

  // queue to stack
  while(!q.empty()){
    s.push(q.front());
    q.pop();
  }
  //stack to queue
  while(!s.empty()){
    q.push(s.top());
    s.pop();
  }

  //final print
   while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
  }
  }