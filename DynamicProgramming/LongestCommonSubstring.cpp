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

  int mn = INT_MIN;
  
  //choiceProgram
  for(int i=1;i<n+1;i++){
    for(int j=1;j<m+1;j++){

      if(a[i-1] == b[j-1])
        dp[i][j] = 1 + dp[i-1][j-1]; //matches then both string moves 1 step further to check other chars and we '+1' since there is one match
      else dp[i][j] = 0;//we are not continuing the max by exploring both the choices or ways, instead we breaking the chain and starting from 0.


      mn = max(mn,dp[i][j]);
    }
  }


  return mn;

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
