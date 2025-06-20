#include <iostream>
using namespace std;

class stack{
  public:
  int*arr;
  int top;
  int size;

  stack(int x){
    size = x;
    arr = new int[x];
    top= -1;  // top here shows the indices number, initially it is at -1 which means the array is empty
  }

  void push(int x){
    if(top==size-1){
        cout<<" stack overflow"<<endl;
    }
    else{
        top++;
        arr[top] = x;
    }
  }

  void pop(){
    if(top==-1){
        cout<<"Stack is empty"<<endl;
    }
    else{
        top--; // top ko ek piche krdene se kaam hojayega(use your brain nikita)
    }
  }

  int peek(){
    if(top==-1){
        cout<<"stack is empty";
        return -1;
    }

    else{
        return arr[top];
    }
  }

  bool isEmpty(){
    if(top == -1){
        return true;
    }
    else{
        return false;
    }
  }

};



int main(){
   
   stack st(4);
   st.push(1);
   st.push(2);
   st.push(3);
   st.push(100);
   cout<<st.peek()<<endl;
   st.push(5);
   st.pop();
   cout<<st.peek()<<endl;
    return 0;
}