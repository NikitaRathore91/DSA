#include <iostream>
using namespace std;
int sum(int arr[],int n){
    if(n==0){
        return 0;
    }
     return arr[0]+ sum(arr+1,n-1);
}
int main(){
   int arr[5] = {1,4,7,4,5};
   int summArray = sum(arr,5);
   cout<<summArray;
    return 0;
}