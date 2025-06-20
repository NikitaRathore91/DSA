/*Given an input stream A of n characters consisting only of lower case alphabets. While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer.

NOTE:
1. You need to find the answer for every i (0 <= i < n)
2. In order to find the solution for every i you need to consider the string from starting position till ith position.
 

Example 1:

Input: A = "aabc"
Output: "a#bb"
Explanation: For every ith character we will
consider the string from index 0 till index i first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - there are two non repeating characters 'b' and 'c', 
first non-repeating character is 'b' because 'b' comes before
'c' in the stream.
*/

#include<iostream>
#include<queue>
using namespace std;
int main(){
    string input;
    cin>>input;
    vector<int>alphaMap(26,0);
    queue<char>q;
    string result;
    int n = input.size();
    for(int i = 0;i<n;i++){
        char c = input[i];
        alphaMap[c-'a']++;
        q.push(c);
        
        while(!q.empty()&&alphaMap[q.front()-'a']>1){
            q.pop();
        }
        if(q.empty()){
            result = result+'#';
        }
        else{
            result = result+q.front();
        }
      
    }

    for(int i = 0 ;i<result.size();i++){
        cout<<result[i];
    }

}