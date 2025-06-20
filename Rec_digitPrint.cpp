#include<iostream>
using namespace std;
void digit(int n){
    if(n==0){
        return;
    }
    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    int mod = n%10;
    
   // int div =n/10;
    digit(n/10);
    cout<< arr[mod]<<" ";
}

int main(){
    int n;
    digit(123);
  return 0;
}