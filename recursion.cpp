#include<iostream>
using namespace std;
int factorial(int n){
    if(n==1){
        return 1;
    }

  return n * factorial(n-1);
}
int main(){
    int hello;
    cin>>hello;
    int m = factorial(hello);
    cout<<m;



    return 0;
}