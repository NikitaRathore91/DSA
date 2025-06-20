#include<iostream>
#include<queue>
using namespace std;
int main(){
  queue<int>q;
  q.push(1);
  q.push(3);
  q.push(5);
  q.push(7);
  q.push(9);

  cout<<"front is :"<<q.front()<<endl;
  cout<<"size is :"<<q.size()<<endl;
  q.pop();
  cout<<"size is :"<<q.size()<<endl;
  cout<<"front is :"<<q.front()<<endl;
  if(q.empty()){
    cout<<"Empty"<<endl;
  }
  else{
    cout<<"Not empty"<<endl;
  }

  


}