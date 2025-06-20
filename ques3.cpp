#include<iostream>
#include<vector>
using namespace std;
void UppertoLower(string &a,int size){

    for(int i = 0;i<size;i++){
    if(a[i]>='A'&&a[i]<='Z'){
        a[i]=a[i]-'A'+97;
    }
    }
}
int main(){
    string a;
    cin>>a;
    vector<char>final;
    int size = a.size();
    UppertoLower(a,size);
    for(int i = 0;i<size;i++){
        if(a[i]!='a'&& a[i]!='i'&&a[i]!='o'&&a[i]!='e'&&a[i]!='u'&&a[i]!='y'){
            final.push_back(a[i]);
        }
    }


    int k = final.size();

    for(int i = 0;i<k;i++){
        cout<<"."<<final[i];
    }


    return 0;
}