/*
Inversion Count for an array indicates – how far (or close) the array is from being sorted. 
If the array is already sorted, then the inversion count is 0, but if the array is sorted in reverse order,
 the inversion count is the maximum. 
*/
/* example
Input: arr[] = {1, 20, 6, 4, 5}
Output: 5
Explanation: Given array has five inversions: (20, 6), (20, 4), (20, 5), (6, 4), (6, 5). 
*/
#include<iostream>
using namespace std;
int main(){
    int n =5;
    int arr[5]={1,20,6,4,5};
    // o/p should be 5
    int cnt =0;
    for(int i =0;i<n-1;i++){
        for(int j =i+1;j<n;j++){
           if(arr[i]>arr[j]){
            cnt++;
           }
        }
    }

    cout<<cnt;
}