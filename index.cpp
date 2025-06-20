#include <iostream>
using namespace std;

int main(){
    
    char ch[] = "namaste";
    cout<<"ch   "<<ch<<endl;
    cout<<"*ch   "<<*ch<<endl;
    cout<<"&ch   "<<&ch<<endl;
    cout<<"ch[0]   "<<ch[0]<<endl;
    cout<<"sizeof(ch)   "<<sizeof(ch)<<endl;
    cout<<"*ch+1   "<<*ch+1<<endl;
    cout<<"*(ch+1)   "<<*(ch+1)<<endl;
    cout<<"0[ch]   "<<0[ch]<<endl;
    cout<<"1[ch]   "<<1[ch]<<endl;
    cout<<"*(ch+3)   "<<*(ch+3)<<endl;
    char *p = &ch[0];
    cout<<"*p   "<<*p<<endl;
    cout<<"p   "<<p<<endl;
    cout<<"*p+1   "<<*p+1<<endl;
    cout<<"*(p+1)   "<<*(p+1)<<endl;
    cout<<"(*p)+1    "<<(*p)+1<<endl;
    cout<<"*p+5    "<<*p+5<<endl;
    cout<<"&p   "<<&p<<endl;
    p++;
    cout<<"p   "<<p<<endl;
    cout<<"*p   "<<*p<<endl;
    cout<<"*p+1    "<<*p+1<<endl;
    cout<<"*(p+1)    f"<<*(p+1);








    

 return 0;
}