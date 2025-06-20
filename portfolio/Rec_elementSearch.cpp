#include<iostream>
using namespace std;
bool search(int arr[],int size,int key){
if(size<0){
    return false;
}
if(arr[0]==key){
        return true;
}
return search(arr+1,size-1,key);

}
int main(){
    int arr[]={1,5,4,2,3};
    //int arr1[]={} 
    cout<<search(arr,5,1)<<endl;
        cout<<search(arr,5,0)<<endl;
            cout<<search(arr,5,3)<<endl;
                cout<<search(arr,5,-2)<<endl;
                    cout<<search(arr,5,9)<<endl;
    
}