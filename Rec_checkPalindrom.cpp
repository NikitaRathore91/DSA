#include<iostream>
using namespace std;
bool check_palimdrom(string abcd,int s,int e){
     if(s>e || s==e){
        return true;
     }
     if(abcd[s]!=abcd[e]){
        return false;
     }
     else{
        s++;
        e--;
        return check_palimdrom(abcd,s,e);
     }

}
int main(){
    string abcd= "abceba";
    int s =0;
    int e = abcd.size()-1;
    cout<<check_palimdrom(abcd,s,e)<<endl;


    return 0;
}