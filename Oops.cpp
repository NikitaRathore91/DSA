#include<iostream>
using namespace std;
class abc{
     public:
    int hello = 6;
    int name;
    char hi = 'a';

    private:
    int duck = 2;
    char x = 7;

    public:

    int getduck(){
        return duck;
    }
    // void setduck(int h){
    //     duck = h ;
    // }

};
int main(){
    abc a;
    cout<<sizeof(a)<<endl;
    cout<<sizeof(abc)<<endl;

    abc h1;
    h1.hello = 5;
    
    cout<<h1.name<<endl;
    cout<<h1.hi<<endl;
    cout<<h1.hello<<endl;

    cout<< h1.getduck()<<endl;
   // h1.setduck(5);
   // cout<< h1.getduck()<<endl;
   
    return 0;
}