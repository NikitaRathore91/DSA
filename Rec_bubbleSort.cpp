#include<iostream>
using namespace std;
void bubbleSort(int*arr,int n){
    if(n==0||n==1){
        return;
    }

    for(int i =0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    bubbleSort(arr,n-1);
}

int main(){
   
   int arr[] ={2,9,4,7,11,3,0};
   int n = sizeof(arr)/sizeof(arr[0]);

   for(int i =0;i<n;i++){
    cout<<arr[i]<<" ";
    }
   cout<<endl;
    
   bubbleSort(arr,n);

   for(int i =0;i<n;i++){
    cout<<arr[i]<<" ";
    }
   cout<<endl;

  return 0;
}