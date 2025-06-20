#include<iostream>
#include<stack>
using namespace std;
void deleteMiddleHelper(stack<int>&st,int current,int middle){
       if(current == middle){
        st.pop();
        return;
       }

       int top = st.top();
       st.pop();
       deleteMiddleHelper(st,current+1,middle);
       st.push(top);
}
// void deleteMiddle(stack<int>&st){
//     if(st.empty()){
//         return;
//     }
//     int middle = st.size()/2;

//     deleteMiddleHelper(st,0,middle);
// }
int main(){
 
 stack<int>st;
 st.push(2);
 st.push(4);
 st.push(6);
 st.push(8);
 st.push(10);

 //deleteMiddle(st);
 int middle = st.size()/2;
 deleteMiddleHelper(st,0,middle);  // i added this given that stack is not empty

 while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
 }

}
