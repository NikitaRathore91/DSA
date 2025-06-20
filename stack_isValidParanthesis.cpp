#include<iostream>
#include<stack>
using namespace std;
bool isValidParan(string s){
  stack<char> abc;
        
        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                abc.push(ch);
            } else {
                if (abc.empty()) {
                    return false;
                }
                char top = abc.top();
                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')) {
                    abc.pop();
                } else {
                    return false;
                }
            }
        }
        
        return abc.empty();
    }

int main(){
     string paran ="{[()]}";
     if(isValidParan(paran)){
        cout<<"valid Palindron"<<endl;
     }

     else{
        cout<<"Not a valid Palindrom"<<endl;
     }

     string paran1 ="({)}";
       if(isValidParan(paran1)){
        cout<<"valid Palindron"<<endl;
     }

     else{
        cout<<"Not a valid Palindrom"<<endl;
     }

     string paran2 ="()[]{}";
       if(isValidParan(paran2)){
        cout<<"valid Palindron"<<endl;
     }

     else{
        cout<<"Not a valid Palindrom"<<endl;
     }

    
    return 0;
}