#include<iostream>
using namespace std;
void reference(int &x){
    x++;
}
void function(int m){
    m++;
}
int main(){
    int i = 5;
    int &j = i;
    // cout<<i<<" "<<j<<endl;
    // i++;
    // cout<<i<<" "<<j<<endl;
    // j++;
    // cout<<i<<" "<<j<<endl;
    // reference(i);
    // cout<<i<<" "<<j<<endl;
    // function(i);
    // cout<<i<<" "<<j<<endl;
    cout<<sizeof(i)<<" "<<sizeof(j)<<endl;
    return 0;
}