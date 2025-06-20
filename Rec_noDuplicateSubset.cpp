#include<iostream>
#include <bits/stdc++.h>
using namespace std;
bool isUnique(vector<int>output,vector<vector<int>>ans){
    auto it = find(ans.begin(),ans.end(),output);

    if(it!=ans.end()){
        return false;
    }
    else{
        return true;
    }
}
void subset2(vector<int>nums,int size,int index,vector<int>output,vector<vector<int>>&ans){
    if(index>=size){
        if(isUnique(output,ans)){
            ans.push_back(output);
            return;
        }
        else{
            return;
        }
    }
     
     //exclude
     subset2(nums,size,index+1,output,ans);

     //include
     output.push_back(nums[index]);
     subset2(nums,size,index+1,output,ans);

}
int main(){
    vector<int>nums({1,2,3});
    int size = nums.size();
    int index =0;
    vector<int>output;
    vector<vector<int>>ans;
    subset2(nums,size,index,output,ans);
    for(int i = 0;i<ans.size();i++){
        for(int j = 0;j<ans.size();j++){
            cout<<ans[i][j]<<" ";
        }
    }

}