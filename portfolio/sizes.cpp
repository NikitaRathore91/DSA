#include<iostream>
#include<vector>

using namespace std;

int main(){
            //array
   int arr[]={1,2,3,4,5,6};
   int arr_size = sizeof(arr)/sizeof(int);
   // sizeof(arr)/sizeof(arr[0]);
   cout<<arr_size<<endl;

            //vector
   vector<int>abc;
   int abc_size = abc.size();
   cout<<abc_size<<endl;
   abc.push_back(1);
   abc.push_back(3);
   cout<<abc.size()<<endl;

          //string
   string hello ="namaste";
   cout<<hello.size()<<endl;

                

  return 0;
}