#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i = 0;
    int ans = 0;
    while(n!=0){
        int lastNum  = n%10;
        if(lastNum !=0){
        ans  = pow(2,i) + ans;
        }
        n = n/10;
        i++;
    }

    cout<<"The number is -> "<<ans;
}