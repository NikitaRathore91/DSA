#include<iostream>
#include<vector>
using namespace std;
void solve(int*arr,vector<vector<int>>&ans,vector<int>output,int target,int index,int size){
   if(target==0){
      ans.push_back(output);
      return;
   }
    
   if(target<0 || index>=size){
    return;
  }

   if(arr[index]<=target){
       output.push_back(arr[index]); 
       //include wala
       solve(arr,ans,output,target-arr[index],index,size);
       output.pop_back();
      
   }
       //exclude wala
       solve(arr,ans,output,target,index+1,size);



   
}
int main(){
    int arr[] ={2,5,6,9};
    int target =9;
    vector<vector<int>>ans;
    int size = 4;
    vector<int>output;
    int index =0;

     solve(arr,ans,output,target,index,size);

}