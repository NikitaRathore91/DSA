#include<iostream>
using namespace std;
bool isDangerous(string a,int n){
    if(n<7){
        return 1;
    }
    int num = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0; j<7;j++){

            num = num + a[i+j]-'0';
           
        }
       // cout<<num;
      
        if(num == 7||num==0){
            return 0;
           }
           num = 0;
       
    }
    return 1;
}
int main(){
    string a ;
    cin>>a;
    int size = a.size();
    if(isDangerous(a,size)){
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }
 
return 0;
}