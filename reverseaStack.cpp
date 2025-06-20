#include<iostream>
#include<stack>
using namespace std;
int main(){
string str = "Nikita";
int size = str.size();

stack<char>ch;
for(int i =0;i<size;i++){
    char abc = str[i];
    ch.push(abc);
}

string ans = "";
while(!ch.empty()){
    char bcd = ch.top();
    ans.push_back(bcd);
    ch.pop();
}

cout<<"answer is "<<ans<<endl;

    return 0;
}