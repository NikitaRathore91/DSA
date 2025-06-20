#include<iostream>
using namespace std;

class twoStack{
    public:
    int size;
    int*arr;
    int top1;
    int top2;

    twoStack(int x){
        size =x;
        arr = new int[x];
        top1 =-1;
        top2 =x;

    }

    void push1(int x){
       // top1++;
        if(top2-top1 == 1){
            cout<<"Stack overflow"<<endl;
        }
        else{
            top1++;
            arr[top1] = x;
        }
    }

    void push2(int x){
       // top2--;
        if(top2-top1 == 1){
            cout<<"stack overflow"<<endl;
        }
        else{
            top2--;
            arr[top2] = x;
        }
    }

    void pop1(){
        if(top1==-1){
            cout<<"stack1 is empty"<<endl;
        }

        else{
            top1--;
        }
    }

    void pop2(){
        if(top2 == size){
            cout<<"Stack2 is empty"<<endl;
        }
        else{
            top2++;
        }
    }

    int peek1(){
    if(top1==-1){
        cout<<"Stack1 is empty";
        return -1;
    }

    else{
        return arr[top1];
    }
    }

    int peek2(){
        if(top2==size){
            cout<<"stack two is empty"<<endl;
        }
        else{
            return arr[top2];
        }
    }

};



int main(){

    twoStack ts(6);
    ts.push1(5);
    cout<<ts.peek1()<<endl;
    ts.push2(10);
    cout<<ts.peek2()<<endl;
    ts.push1(15);
    cout<<ts.peek1()<<endl;
    ts.push2(20);
    cout<<ts.peek2()<<endl;
    ts.push1(25);
    cout<<ts.peek1()<<endl;
    ts.push2(30);
    cout<<ts.peek2()<<endl;



    return 0;
}