#include<bits/stdc++.h>
using namespace std;
int board[21][21];


void printBoard(int n){

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      cout<<board[i][j]<<" ";
      cout<<endl;
  }

}


bool isSafe(int row,int col,int n){

  int i,j;

  //straight bottom
  for(i=0;i<row;i++)
    if(board[i][col]) //if a queen exists in this position
      return 0;

  //diagonal left bottom
  for(i=row,j=col;i>=0 && j>=0;i--,j--) //row & column will decrease
    if(board[i][j])
      return 0;

  //diagonal right bottom
  for(i=row,j=col;i>=0 && j<n;i--,j++) //row will decrease and the column will increase
    if(board[i][j])
      return 0;

  return 1; //if all the paths does not have any queen , then we are good to go.

}


bool isCheck(int n,int row){

  if(row >= n)
    return 1;


  for(int i=0;i<n;i++){ //checking different positions in this row, i.e., horizontally(column)

    if(isSafe(row,i,n)){

      board[row][i] = 1;
      if(isCheck(n,row+1)) //checking the future if we go by this column position for the current row
        return 1;

      //if this config does not works out in the future
      board[row][i] = 0;
    }

  }

  return 0;//if none of the column positions worked out
}


bool solve(){

  int n;
  cin>>n;

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      board[i][j] = 0;


  if(!isCheck(n,0)){
    cout<<-1<<endl;
    return 0;
  }

  printBoard(n);

  return 1;

}


int main(){

  int t;
  cin>>t;

  while(t--){

    solve();

  }

  return 0;
}
