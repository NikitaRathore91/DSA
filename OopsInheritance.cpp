#include<iostream>
using namespace std;
class papa{
   public:
    string name;
    int age;
    int weight;

    int getage(){
        return this-> age;
    }

    void setage(int h){
       this-> age = h;
    }

    void work(){
        cout<<"papa is working properly"<<endl;
    }

};

class beta: public papa{
    public:
    void hello(){
        cout<<"beta is working properly"<<endl;
    }

};

class beti: protected papa{
    public:
    void hello(){
        cout<<"beti is working properly"<<endl;
    }

    int getage(){
        return this->age;
    }
    int getweight(){
        return this->weight;
    }
    void setage(int h){
        this -> age = h;
    }



};
int main(){

    papa ramdas;
    cout<<ramdas.age<<endl;
    cout<<ramdas.weight<<endl;
    ramdas.work();
    ramdas.setage(52);
    cout<<ramdas.age<<endl;

    beta shivraj;
    cout<<shivraj.age<<endl;
    cout<<shivraj.weight<<endl;
    shivraj.work();
    shivraj.setage(20);
    cout<<shivraj.age<<endl;
    shivraj.hello();

    beti Nikita;
    cout<<Nikita.getage()<<endl;
    cout<<Nikita.getweight()<<endl;
    Nikita.hello();
    Nikita.setage(21);
    cout<<Nikita.getage()<<endl;
    Nikita.hello();



    return 0;
}