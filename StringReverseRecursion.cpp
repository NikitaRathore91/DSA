#include<iostream>
using namespace std;

void reverseString(string name,int s, int e){
    
    if(s>=e){
        cout<<name;
        return ;
    }
    swap(name[s],name[e]);
    s++;
    e--;
    
    reverseString(name,s,e);
}

int main(){
    string name = "abcde";
    int size = name.size();
    
     reverseString(name,0,size-1);
  
   return 0;  
}