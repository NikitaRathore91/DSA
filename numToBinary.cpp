#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main(){
   int n ;
   cin>>n;
   string ans = "";

   while(n!=0){
    int bit  =  n&1;
    ans = to_string(bit)+ ans;
    n = n>>1;
   }

   if(ans ==""){
    ans = "0";
   }
   
   cout<<"Bianry is -> "<< ans ;
   return 0 ;
}