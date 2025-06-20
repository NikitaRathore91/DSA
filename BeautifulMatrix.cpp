#include <iostream>
using namespace std;

int main(){
    int mat[5][5];
    for(int i = 0; i<5;i++){
      for(int j = 0;j<5;j++){
        cin>>mat[i][j];
      }
     
    }
 
    int row = 0;
    int col = 0;

     for(int i = 0; i<5;i++){
      for(int j = 0;j<5;j++){
        if (mat[i][j]==1){
            row = i;
            col = j;
        }
          } 
             }


      int inrow;
      int incol;
      if(row>5/2){
        inrow = row-2;
      }
      else{
        inrow=2-row;
      }

      if(col>5/2){
        incol = col-2;
      }
      else{
        incol=2-col;
      }

      int sum = incol+inrow;
      cout<<sum;
     
   
   return 0;
}
