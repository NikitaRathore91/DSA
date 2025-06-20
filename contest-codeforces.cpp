#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    int n;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
      
    }
    stack<int>st;
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            string now = s[i];
            if(now[j]=='#'){
                st.push(j+1);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

    }

    return 0;
    }