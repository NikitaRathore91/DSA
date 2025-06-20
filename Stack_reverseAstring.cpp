#include<iostream>
#include<stack>
using namespace std;
int main(){
   string s ="Nikita";
   int s_size =s.size();
   stack<char>ch;
   
   for(int i =0;i<s_size;i++){
      ch.push(s[i]);
   }

   string ans ="";

   while(!ch.empty()){
     char abc = ch.top();
     ans.push_back(abc);
     ch.pop();
   }

   cout<<"reversed string vis stack is ->"<<ans<<endl;

}