#include <iostream>
#include <string>
#include<vector>
using namespace std;
void number(string&s,int size,vector<int>&x){
    //vector<int>x;
    int num = 0;
    for(int i = 0;i<size;i=i+2){
        num = num + (s[i]-'0');
       x.push_back(num);
       num = 0;
    }
    
   // int k = x.size();

}
void sort(vector<int>&x,int si){
    for(int i = 0;i<si-1;i++){
        for(int j = 0 ; j<si-1-i;j++){
            if(x[j]>x[j+1]){
                swap(x[j],x[j+1]);
            }
        }
    }
    for(int i = 0;i<si;i++){
        if(i==si-1){
            cout<<x[si-1];
        }
   else{ cout<<x[i]<<"+";}
}
}

int main(){
    string s;
    cin>>s;
    int size = s.size();
    vector<int>x;
    number(s,size,x);
    int si = x.size();
    sort(x,si);
    return 0;
}