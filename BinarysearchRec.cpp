#include <iostream>
using namespace std;
bool binarySearch(int arr[], int s, int e , int key){
    if(s>e){
        return false;
    }

    int mid = s + (e-s)/2;

    if(arr[mid]==key){
        return true;
    }

    if(arr[mid]<key){
     
       return binarySearch(arr,mid+1,e, key);
    }
    else {
       
         return binarySearch(arr,s,mid-1,key);
    }


}
  
int main(){
 
    int arr[7]={5,6,7,8,9,10,11};
    int key = 4;
    if (binarySearch(arr,0,6,key)){
        cout<<" found";
    }
    else { cout<<" Not found";}

    return 0;
}