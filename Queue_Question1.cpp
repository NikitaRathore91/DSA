/* Given an array A[] of size N and a positive integer K, find the first negative integer for each and every 
window(contiguous subarray) of size K.
we are doing with deque,but this is not optimal approach 
*/



#include <bits/stdc++.h>
using namespace std;

vector<int> printFirstNegativeInteger(int arr[],int n,int k) {
         deque<int> dq;
         vector<int> ans;
         int negative = -1;
         
         //process first window
         for(int i=0; i<k; i++) {
             if(arr[i] < 0) {
                 dq.push_back(i);
             }
         }
         
         //push ans for FIRST window
         if(dq.size() > 0) {
             ans.push_back(arr[dq.front()]);
         }
         else
         {
             ans.push_back(0);
         }
         
         //now process for remaining windows
         for(int i = k; i<n; i++) {
             //first pop out of window element
             
             
             if(!dq.empty() && (i - dq.front())>=k ) {
                 dq.pop_front();
             }
             
             //then push current element
             if(arr[i] < 0)
                dq.push_back(i);
             
            // put in ans
            if(dq.size() > 0) {
                 ans.push_back(arr[dq.front()]);
            }
            else
            {
                ans.push_back(0);
            }
         }
         return ans;
 }


int main() {

    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;  // Window size

    vector<int> ans = printFirstNegativeInteger(arr, n, k);

    // Output the result
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
