#include<iostream>
using namespace std;

bool ifHello(string hello,string input){

   int j =0;
    for(int i ;i<input.size();i++){
        if(hello[j]==input[i]){
             j++;
             if(j==5){
                return true;
             }
        }
    }
 return false;
}

int main(){
 string hello = "hello";
 string input;
 cin>>input;

 
 if (ifHello(hello, input)) {
        cout << "YES"; // Vasya managed to say hello
    } else {
        cout << "NO"; // Vasya didn't manage to say hello
    }
// int size = hello.size();
 
return 0;
}