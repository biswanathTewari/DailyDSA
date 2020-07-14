#include<bits/stdc++.h>
using namespace std;

int grid[21][21];


void printGrid(int n){

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      cout<<grid[i][j]<<" ";
    cout<<endl; //to pass GFG testCases use this at line number 14.
  }

}


bool isSafe(int row,int col,int num,int n){

  //the box should be empty , so that we can assign the number
  if(grid[row][col] != 0)
    return false;

  //if used in the current sub box
  int startrow = row - (row%3);
  int startcol = col - (col%3);
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      if(grid[i+startrow][j+startcol] == num)
        return false;


  //if used in the column
  for(int i=0;i<n;i++)
    if(grid[i][col] == num)
      return false;


  //if used in the row
  for(int i=0;i<n;i++)
    if(grid[row][i] == num)
      return false;


  return true;//safe to use this number

}


bool FindEmptyBox(int &row,int &col,int n){

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if(grid[i][j] == 0){
        row = i;
        col = j;
        return true;
      }

  return false;
}


bool sudoku(int n){

  int row,col;

  if(!FindEmptyBox(row,col,n)) //finding the next empty box
    return true;

  for(int i=1;i<=9;i++){ //trying out numbers from 1 to 9 on the empty box

    if(isSafe(row,col,i,n)){

      grid[row][col] = i;

      if(sudoku(n)) //checking the next empty box
        return true;

      grid[row][col] = 0; //if placing i at (row,col) does not works out

    }

  }

  return false; //none of the numbers worked for this empty box

}


bool solve(){

  int n;
  n = 9;

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>grid[i][j];

  if(sudoku(n) == false){
    cout<<-1<<endl;
    return false;
  }

  printGrid(n);

  return true;

}


int main(){

  int t;
  cin>>t;

  while(t--){

    solve();

  }

}
