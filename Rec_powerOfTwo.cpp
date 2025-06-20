#include<iostream>
using namespace std;

int power(int x){
if(x ==1){
    return 2;
}
  return 2*power(x-1);
}

int main(){
    
    int x =4;
    cout<<power(4);
    return 0;
}