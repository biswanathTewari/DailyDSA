#include<bits/stdc++.h>
using namespace std;

int LCS(string a,string b,int n,int m){

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

  int super = n+m;
  return (super - dp[n][m]); //n+m is the superseqeunce and we are subtracting the common part from it , that is the LCS(longest common subsequence)

}


int main(){
  int t;
  cin>>t;
  while(t--){

      int n,m;

      string a,b;
      cin>>a>>b;

      n = a.length();
      m = b.length();

      cout<<LCS(a,b,n,m)<<endl;

  }

  return 0;
}
