#include <iostream>
using namespace std;
int power(int a , int b){
    if(b==0){
        return 1;
    }
    else {
    return a * power(a, b-1);
    }
}
int main(){
    int a,b;
    cin>>a>>b;
    int num = power(a,b);
    cout<<num;



    return 0;
}