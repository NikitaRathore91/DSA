#include <bits/stdc++.h>
using namespace std;

void sortAndMerge(int arr[],int s,int mid,int e){
int n1 =  mid-s+1;
int n2 = e-mid;
int leftArray[n1];
int rightArray[n2];

for(int i = 0;i<n1;i++){
  leftArray[i] = arr[s+i];
}
for(int i = 0;i<n2;i++){
  rightArray[i] = arr[mid+1+i];
}

int i = 0 ; int j = 0; int k = s;
// i-> leftArray
// j->rightArray
while(i<n1 && j<n2){
  if(leftArray[i]<rightArray[j]){
    arr[k] = leftArray[i];
    i++;
  }
  else{
    arr[k] = rightArray[j];
    j++;
  }
  k++;
}
while(i<n1){
  arr[k] = leftArray[i];
  i++;
  k++;
}
while(j<n2){
  arr[k] = rightArray[j];
  j++;
  k++;
}
}


void mergeSort(int arr[],int s,int e){
  if(s>=e) return;
  int mid = s+(e-s)/2;

  mergeSort(arr,s,mid);
  mergeSort(arr,mid+1,e);

  sortAndMerge(arr,s,mid,e);
}

int main() {
  int arr[] = {6,1,9,3,2,8,5,4,7,0};
  int n = 10;
  mergeSort(arr,0,9);

  for(int i = 0;i<n;i++){
    cout<<arr[i]<<" ";
  }
return 0;
}