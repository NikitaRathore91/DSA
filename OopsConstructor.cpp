#include <iostream>
using namespace std;
class hero{

  
    public :
    int x;

    hero(){
        cout<<" This is constructor"<<endl;
    }

    hero(int x){
        this -> x =x;
    }

    int getx(){
        return x;
    }

    void setx(int m){
     x = m;
    }

};
int main(){
   // cout<<"this is main"<<endl;
    //static way
    hero a(10);
  
   //f cout<<" end of main"<<endl;
    
   cout<< a.getx()<<endl;

   //dynamic way

   hero *b = new hero(5);

   cout<< (*b).getx()<<endl;



    return 0;
}