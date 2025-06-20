#include<iostream>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    cout<<str<<endl;
    str.push_back('a');
    cout<<str<<endl;
    str.pop_back();
    cout<<str<<endl;
}