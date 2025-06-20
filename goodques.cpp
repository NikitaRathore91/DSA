#include <iostream>
#include <string>
#include<vector>
using namespace std;

int main(){
      string a ;
      cin>>a;
      int alpha[26]= {0};
      int num ;
      int size = a.size();
      for(int i = 0;i<size;i++){
        num = a[i]-'a';
        alpha[num]++;
        num = 0;
      }
    
     char h='a';
      vector<char>final;
      
      for(int i = 0;i<26;i++){
        if(alpha[i]==1||alpha[i]>1){
            final.push_back(h+i);
        }
      }


     int k = final.size();

     if(k%2==0){
        cout<<"CHAT WITH HER!";
      }
      else{
        cout<<"IGNORE HIM!";
      }


    return 0;
}