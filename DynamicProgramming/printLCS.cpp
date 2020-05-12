#include<bits/stdc++.h>
using namespace std;

string LCS(string a,string b,int n,int m){

  int dp[n+1][m+1];

  memset(dp,0,sizeof(dp));

  //baseCase
  for(int i=0;i<n+1;i++){
    for(int j=0;j<m+1;j++){
      if(i == 0 || j == 0) //any one string is empty
        dp[i][j] = 0;
    }
  }


  //choiceProgram
  for(int i=1;i<n+1;i++){
    for(int j=1;j<m+1;j++){

      if(a[i-1] == b[j-1])
        dp[i][j] = 1 + dp[i-1][j-1]; //matches then both string moves 1 step further to check other chars and we '+1' since there is one match
      else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);//exploring both the choices or ways

    }
  }


  int i=n,j=m;
  string s;

  //print calculations
  while(i>0 && j>0){

    if(a[i-1] == b[j-1]){//if matches then move diagonally up
      s.push_back(a[i-1]);
      i--;
      j--;
    }
    else{
      if(dp[i-1][j] >= dp[i][j-1])//move towards max direction
        i--;
      else j--;
    }
  }

  reverse(s.begin(),s.end());


  return s;

}


int main(){
  int t;
  cin>>t;
  while(t--){

      int n,m;
      cin>>n>>m;

      string a,b;
      cin>>a>>b;

      cout<<LCS(a,b,n,m)<<endl;

  }

  return 0;
}
