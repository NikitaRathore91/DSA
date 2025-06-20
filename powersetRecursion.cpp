#include<iostream>
#include<vector>
using namespace std;
void solve(int arr[],vector<int>&output,int index,vector<vector<int>>&ans,int size){
  if(index>=size){
    ans.push_back(output);
    return;
  }
  //exclude
  solve(arr,output,index+1,ans,size);

  //include
  int element = arr[index];
  output.push_back(element);
  solve(arr,output,index+1,ans,size);
  output.pop_back();

}
int main(){
      
      int arr[]={1,2,3,4};
     int size =  sizeof(arr)/sizeof(arr[0]);

      vector<vector<int>>ans;
      vector<int>output;
      int index = 0;
      solve(arr,output,index,ans,size);

      // Printing the subsets
    for (int i = 0; i < ans.size(); ++i) {
        cout << "[";
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << "]" << endl;
    }

    

    return 0;
}