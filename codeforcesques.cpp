#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
// #include <iomanip>
// #include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    int n;
   
    cin>>t;
    while(t--){
      cin>>n;
    int arr[n];
     
    for(int i =0;i<n;i++){
      arr[i]=i+1;
      
    }
    int sum =0;
    for(int i =0;i<n;i++){
      sum = sum+arr[i];
    }
   int a =0;
   int b =n-1;
   if(n==1){
    cout<<"1"<<endl;
   }
    else{
    while(a<b){
      if(sum%(b-a+1)==0){
        cout<<"-1"<<endl;
      }

      else{
        for(int i =0;i<n;i++){
          cout<<arr[i]<<" ";
      
    }
    cout<<endl;
      }

      a++;
      b--;
    }


    }}

    return 0;
} 