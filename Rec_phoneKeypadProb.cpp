#include<iostream>
#include<vector>
using namespace std;
void solve(string digit,int index,string output,vector<string>&ans,string mapping[]){
    if(index>=digit.size()){
      cout<<"when index is greater then size "<<output<<endl;
        ans.push_back(output);
        return;
    }
    cout<<" index is "<<index<<endl;
    int num = digit[index]-'0';
    string value = mapping[num];
    
    for(int i =0;i<value.size();i++){
        output.push_back(value[i]);
        cout<<"value["<<i<<"] is "<<value[i]<<endl;
        solve(digit,index+1,output,ans,mapping);  
        cout<<"output is "<<output<<endl; 
        output.pop_back();
    }

}


int main(){
   string mapping[] ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
   vector<string>ans;
   string output ="";
   int index = 0;
   string digit;
   cin>>digit;

  if(digit.size()==0){
    cout<<"";
  }
  else{
    solve(digit,index,output,ans,mapping);

  }

  for(int i =0;i<ans.size();i++){
    cout<<ans[i]<<endl;
  }


}