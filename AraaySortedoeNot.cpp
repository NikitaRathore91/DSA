#include <iostream>
using namespace std;
bool sorted(int arr[],int n ){
 if(n==1){
    return true;
 }
 if(arr[0]>arr[1]){
    return false;
 }
 sorted(arr+1,n-1);
}
int main(){
   int arr[6] = {1,2,5,10,11,9};
   if(sorted(arr,6)){
    cout<<" Sorted";
   }
   else {
    cout<<"Not sorted";
   }


    return 0;
}