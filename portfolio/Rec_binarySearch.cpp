#include<iostream>
using namespace std;
bool binSearch(int arr[],int s,int e,int key){
     if(e<s){
        return false;
    }

    int mid = s+(e-s)/2;
    
    if(key==arr[mid]){
        return true;
    }
   
    if(key>arr[mid]){
        return binSearch(arr,mid+1,e,key);
    }
    else{
        return binSearch(arr,s,mid-1,key);
    }
}
int main(){
   int arr[]={2,3,5,8,10,11};
   int s =0;
   int e = 5;

   cout<<binSearch(arr,s,e,10)<<endl;
   cout<<binSearch(arr,s,e,0)<<endl;
   cout<<binSearch(arr,s,e,-100);


  return 0;
}