#include<iostream>
#include<vector>
using namespace std;
void subseq(string a,int size,int index,string output,vector<string>&ans){
    if(index>=size){
        ans.push_back(output);
        return;
    }
    //exclude
    subseq(a,size,index+1,output,ans);

    //include
    char ch = a[index];
    output.push_back(ch);
    subseq(a,size,index+1,output,ans);
    
}
int main(){
    string a ="abc";
    int size = a.size();
    int index =0;
    string output ="";
    vector<string>ans;
    subseq(a,size,index,output,ans);

    for(int i =0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

    

}