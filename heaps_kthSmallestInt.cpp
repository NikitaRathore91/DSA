#include<iostream>
using namespace std;
void heapify(int arr[],int n,int i){
    int largest =i;
    int left = 2*i;
    int right = 2*i+1;
    if(left<=n && arr[left]>arr[largest]){
        largest = left;
    }

    if(right<=n && arr[right]>arr[largest]){
        largest = right;
    }

    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void findKthSmallestElement(int arr[],int k,int n){
    for(int i = k/2 ;i>=1;i--){
        heapify(arr,k,i);
    }

    for(int i = 1;i<=k;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i = k+1;i<=n;i++){
        if(arr[i]<arr[1]){
            swap(arr[i],arr[1]);
             for(int i = k/2 ;i>=1;i--){
                heapify(arr,k,1);
              }

        }
    }
    cout<<"The kth smallest element is -> "<<arr[1];
}
int main(){
    int arr[] = {-1,5,10,3,1,2,7,15};
    int n = 7;
    int k =4;
    findKthSmallestElement(arr,k,n);

}