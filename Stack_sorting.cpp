#include<iostream>
#include<stack>
using namespace std;
void arrange(stack<int>&s,int x){
    if(s.empty() || s.top()<=x){
        s.push(x);
        return;   
    }

       int top = s.top();
       s.pop();
       arrange(s,x);
       s.push(top);
    

}
void sort(stack<int>&s){
    if(s.empty()){

        return;

    }

    int top = s.top();
    s.pop();
    sort(s);
    arrange(s,top);
}
int main(){
 stack<int>s;
 s.push(5);
 s.push(-2);
 s.push(9);
 s.push(-7);
 s.push(3);
 cout<<" before loop"<<" ";
   stack<int> temp = s; // Temporary stack to display elements
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

 sort(s);
 cout<<" after loop ";
 while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
 }
}
