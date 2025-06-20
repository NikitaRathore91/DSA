#include<iostream>
using namespace std;
int sum(int arr[],int size,int cnt){
   // int cnt =0;
    if(size==0){
        return cnt;
    }
    // cnt = cnt+arr[0];
     return arr[0]+ sum(arr+1,size-1,cnt);
}

int main(){
 int arr[] ={2,2,3,5,5};
 int cnt=0;
 cout<<sum(arr,5 ,0); 


  return 0;
}