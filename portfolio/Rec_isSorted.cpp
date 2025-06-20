#include<iostream>
using namespace std;
bool isSorted(int arr[],int size){
    if(size==0||size==1){
        return true;
    }
    else{
        if(arr[0]>arr[1]){
            return false;
        }
        return isSorted(arr+1,size-1);
    }
}

int main(){
    int arr[] ={2,3,5,11,19};
    int arr1[]={2,6,4,7,8,9};

    cout<<isSorted(arr,5)<<endl;
    cout<<isSorted(arr1,6);

  return 0;
}