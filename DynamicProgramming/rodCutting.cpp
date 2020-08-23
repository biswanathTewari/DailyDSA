#include<bits/stdc++.h>
using namespace std;

int rodCutting(int a[],int n){

  int dp[n+1][n+1];

  //baseCase
  for(int i=0;i<n+1;i++){
    for(int j=0;j<n+1;j++){
      if(i == 0 || j == 0)
        dp[i][j] = 0;
    }
  }


  //choiceProgram
  for(int i=1;i<n+1;i++){
    for(int j=1;j<n+1;j++){

      //if we dont take it
      if(i > j)
        dp[i][j] = dp[i-1][j];

      //if we take it
      if(i <= j)
        dp[i][j] = max(a[i-1]+dp[i][j-i],dp[i-1][j]);

    }
  }


  return dp[n][n];

}



int main(){

  int t;
  cin>>t;

  while(t--){

  int n;
  cin>>n;

  int a[n];

  for(int i=0;i<n;i++)
    cin>>a[i];

  cout<<rodCutting(a,n)<<endl;

  }
  return 0;
}
