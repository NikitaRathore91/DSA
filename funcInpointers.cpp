#include<iostream>
using namespace std;
void print(int *p){ 
    cout<<p<<endl;
    cout<<*p<<endl;
}
void update(int *p){
    cout<<"in function"<<endl;
    cout<<p<<endl;
    cout<<*p<<endl;
    (*p)++;
    cout<<p<<endl;
    cout<<*p<<endl;
    p++;
    cout<<p<<endl;
    cout<<*p<<endl;
}

int main(){
    int value = 5;
    int *p = &value;
    cout<<p<<endl;
    cout<<*p<<endl;
    update(p);
    cout<<"after update"<<endl;
    cout<<p<<endl;
    cout<<*p<<endl;


 return 0;
}