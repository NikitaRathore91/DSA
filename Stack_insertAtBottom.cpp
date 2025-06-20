#include<iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>&abc,int x){
    //int count = 0;
    if(abc.empty()){
      abc.push(x);
      return;
    }
  
    int top = abc.top();
    abc.pop();
    insertAtBottom(abc,x);
    abc.push(top);

}
int main(){
    stack<int>abc;
    abc.push(1);
    abc.push(2);
    abc.push(3);
    abc.push(4);
    abc.push(5);

    int abc_size = abc.size();
    int x;
    cout<<abc_size<<endl;
    cout<<"enter the number you want to insert @ bottom ";
    cin>>x;
    insertAtBottom(abc,x);
    cout<< abc.size()<<endl;
    abc.pop();
    abc.pop();
    abc.pop();
    abc.pop();
    abc.pop();
    cout<<abc.top();
    

    return 0;
}

