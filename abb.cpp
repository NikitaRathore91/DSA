#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    int num[2*n];
    int j =0;
    for(int i = 0;i<n;i++){
        if(i<n){
            num[i]=arr[j];
            j++;
        }
    }
    
    j = 0;

    for(int i =n;i<2*n;i++){
        
        if(i>=n){
           // j =0;
            num[i]=arr[j];
            j++;
        }
    }

    for(int i =0;i<2*n;i++){
        cout<<num[i]<<" ";
    }


    return 0;
}