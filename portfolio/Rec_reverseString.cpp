#include<iostream>
using namespace std;
string revString(string abc,int size,int cnt){
   // int cnt = 0;
    if(cnt==size/2){
        
       return abc;
    }
    swap(abc[cnt],abc[size-cnt-1]);
    cnt++;
    return revString(abc,size,cnt);

}

void reverse(string &abc,int i,int j){
    if(i>j){
        return;
    }

    swap(abc[i],abc[j]);
    i++;j--;
    reverse(abc,i,j);
}

int main(){
   string abc;
   cin>>abc;
   int size =abc.size();
   int cnt =0;
   cout<< revString(abc,size,cnt)<<endl;
   string a ="asdfg";
   cout<<a<<endl;
   reverse(a,0,a.size()-1);
   cout<<a<<endl;


  return 0;
}