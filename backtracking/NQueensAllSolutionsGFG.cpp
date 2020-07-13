#include<bits/stdc++.h>
using namespace std;
int board[21][21];

vector<vector<int>> v;
vector<int> jr;


void printBoard(){

  for(auto i:v){ // i is traversing the vector v
    cout<<"[";
    for(auto j:i) //j is traversing the vector v[current_iterator]
      cout<<j<<" ";
    cout<<"]"<<" ";
  }

  cout<<endl;

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

  if(row >= n){
      v.push_back(jr); //pushing current positions of the queens in the board
      return 1;
  }

  int res = 0;

  for(int i=0;i<n;i++){ //checking different column positions in this row, i.e., horizontally(column)

    if(isSafe(row,i,n)){

      board[row][i] = 1; //placing the queen here
      jr.push_back(i+1); //pushing the column no. of the queen

      res = isCheck(n,row+1) || res; //if placing the queen in any of the columns works

      //if this config does not works out in the future
      board[row][i] = 0;
      jr.pop_back();
    }

  }

  return res;
}


bool solve(){

  int n;
  cin>>n;

  v.clear();
  jr.clear();

  for(int i=0;i<n;i++) //empting the board
    for(int j=0;j<n;j++)
      board[i][j] = 0;


  if(!isCheck(n,0)){ //if not possible
    cout<<-1<<endl;
    return 0;
  }

  sort(v.begin(),v.end());

  printBoard();

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
