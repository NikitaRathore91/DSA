#include<iostream>
using namespace std;

class A{
    public:

    void hello(){
        cout<<"in hello function of class A"<<endl;
    }
};

class B{
    public:

    void hello(){
        cout<<"in hello function of class B"<<endl;
    }
};

class C:public A,public B{

};
int main(){

    C name;
    name.A::hello();
    name.B::hello();


    return 0;
}