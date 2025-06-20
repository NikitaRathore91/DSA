#include<iostream>
using namespace std;
class qu{
    public:
    int front;
    int rear;
    int*arr;
    int size;
    qu(int x){
        size = x;
        front = 0;
        rear = 0;
        arr= new int[size];
    }

    void push(int y){
        if(rear ==size){
            cout<<"Overflow !!"<<endl;
        }
        else{
            arr[rear] = y;
            rear++;
        }
    }

    void pop(){
    if(rear==front){
        cout<<"No element to pop !"<<endl;
        rear = 0;
        front = 0;
    }   
    else{
        arr[front] = -1;
        front++;
    } 
    }

    void empty(){
        if(rear==front){
            cout<<"Queue is empty"<<endl;
        }
        else{
            cout<<"Queue is not empty"<<endl;
        }
    }

    int peek(){
        return arr[front];
    }

};
int main(){
qu queue1(5);
queue1.pop();
queue1.push(1);
queue1.push(3);
int f =queue1.peek();
cout<<f<<endl;
queue1.empty();

}