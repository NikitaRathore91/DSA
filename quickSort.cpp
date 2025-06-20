#include<iostream>
using namespace std;
int partition(int* arr, int s,int e){
    int pivot = arr[s];
    int count = 0;
    for(int i= s+1;i<=e;i++){
       if(arr[i]<pivot){
        count ++;
       }
    }
    int pivotIndex = s+count;
    swap(arr[s],arr[pivotIndex]);
    
    int i =s;
    int j = e;

    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<arr[pivotIndex]){
            i++;
        }
        while(arr[j]>pivotIndex){
          j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    

   return pivotIndex;

}

void quickSort(int* arr, int s , int e){
    if(s>=e){
        return;
    }
    int p = partition(arr,s,e);


   //sorting left part
    quickSort(arr,0,p-1);

  //sorting right part
    quickSort(arr,p+1,e);



}
int main(){
    int n = 6;
    int arr[n] = { 5 ,9 ,2, 0 , 3, 9};

     quickSort(arr,0,n-1);

    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }



    return 0;
}