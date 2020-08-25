/*
https://practice.geeksforgeeks.org/problems/boolean-matrix-problem/0
DailyDSA: biZan7X
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

int main(){

  int t;
  cin>>t;

  while(t--){

    int r,c;
    cin>>r>>c;

    int matrix[r][c];
    int row[r],col[c];

    fill(row,row+r,0);
    fill(col,col+c,0);

    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){

        cin>>matrix[i][j];

        if(matrix[i][j]){
          row[i] = 1;
          col[j] = 1;
        }

      }
    }



    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++)
        if(row[i] || col[j])
          cout<<1<<" ";
        else cout<<0<<" ";
      cout<<endl;
    }


  }

  return 0;
}
