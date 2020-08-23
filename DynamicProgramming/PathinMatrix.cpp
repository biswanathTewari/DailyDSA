/*kinda like a variation of LIS(logic) : O(N^2)*/
#include<bits/stdc++.h>
using namespace std;

int a[1001][1001];

int PathMatrix(int n){

  int dp[n][n];

  memset(dp,INT_MIN,sizeof(dp));

  //baseCase
  for(int i=0;i<n;i++)
    dp[0][i] = a[0][i];//for the row -> 0 , a[0][i] is the highest sum for each (0,i)


  //choiceProgram
  for(int i=1;i<n;i++){
    for(int j=0;j<n;j++){

      //upwards
      dp[i][j] = max(dp[i][j],a[i][j]+dp[i-1][j]);

      //diagonal left-up
      if(j - 1 >= 0){
        dp[i][j] = max(dp[i][j],a[i][j]+dp[i-1][j-1]);
      }

      //diagonal right-up
      if(j + 1 < n){
        dp[i][j] = max(dp[i][j],a[i][j]+dp[i-1][j+1]);
      }


    }
  }


  int mx = INT_MIN;

  for(int i=0;i<n;i++)
    mx = max(mx,dp[n-1][i]);

  return mx;

}

int main(){

  int t;
  cin>>t;

  while(t--){
    int n;
    cin>>n;

    memset(a,0,sizeof(a));

    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        cin>>a[i][j];

    cout<<PathMatrix(n)<<endl;
  }

  return 0;
}
