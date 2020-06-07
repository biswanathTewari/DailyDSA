#include<bits/stdc++.h>
using namespace std;

int Optimal(int a[],int n){

  int dp[n][n];

  //baseCase
  for(int i=0;i<n;i++){
    for(int j =0;j<n;j++){

      if(i == j)//range is 1
        dp[i][j] = a[i];

      if(i+1 == j)//range is 2
        dp[i][j] = max(a[i],a[j]);

    }
  }


  //choiceProgram
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){

      dp[i][j] = max((a[i]+min(dp[i+2][j],dp[i+1][j-1])) , (a[j]+min(dp[i][j-2],dp[i+1][j-1])));

    }
  }

  return dp[0][n-1];

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

    cout<<Optimal(a,n)<<endl;

  }

  return 0;
}
