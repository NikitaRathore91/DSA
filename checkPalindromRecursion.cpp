#include <iostream>
using namespace std;
bool palindrom(string hello,int s,int e){
    if(s>=e){
        return true;
    }
    if(hello[s]!=hello[e]){
       return false;
    }
    else {
        s++;
        e--;
        return palindrom(hello,s,e);

    }

}

int main(){
    string hello = "acbmmbca";
    int size = hello.size();
    if(palindrom(hello,0,size-1)){
        cout<<"Palindrom";
    }
   else {
    cout<<" Not palinrom";
   }
   return 0;
}