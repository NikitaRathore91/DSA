#include <iostream>
using namespace std;
void count(int n){
    if (n==0){
        return ;
    }
   

   count(n-1);
   cout<<n<<" ";
}

int main(){
    int m = 10;
   // int op= 
    count(m);
   // cout<<op;

 
    return 0;
}