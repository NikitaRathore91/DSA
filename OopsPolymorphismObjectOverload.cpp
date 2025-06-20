#include<iostream>
using namespace std;
class hello{
    public:
    int a;
    void operator+( hello &x){
        int value1 = this -> a;
        int value2 = x.a;
        cout<<"final output "<<value2 - value1 <<endl;

    }
  
};

int main(){

    hello var1 ,var2;
    var1.a = 3;
    var2.a = 9;

    var1+var2;




return 0;
}