#include<iostream>
using namespace std;
bool isPrime(int n){

    if(n<=1)  return false;

    for(int i = 2 ; i*i<=n ;i++){
         if(n%i == 0){
            return false;
         }
    }
    return true;

}

void printPrime(int limit){
    cout<<"Prime number upto"<<limit<<"are ->";
    for(int i = 2;i<=limit;i++){
        if(isPrime(i)){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

int main(){
    int n ;
    cout<<"Enter the number you want to check ->";
    cin>>n;
    if(isPrime(n)){
        cout<<"The given number is prime "<<endl;
    }
    else{
        cout<<"The given number is not prime"<<endl;
    }
    
    int limit;
    cout<<"Enter the limit ";
    cin>>limit;
    printPrime(limit);

    return 0;
}