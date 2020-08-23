/*variation of LIS : O(N^2)*/
#include<bits/stdc++.h>
using namespace std;

int LIS(int a[],int n){

  int dp[n];

  fill(dp,dp+n,INT_MAX);

  //baseCase
  dp[0] = 0;//0 jumps

  for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){

      if(i - j <= a[j] && dp[j]!=INT_MAX){ //if point j has the capacity to make a jump from j to i.
        dp[i] = min(dp[i],dp[j]+1);
      }

    }
  }

  return (dp[n-1] == INT_MAX) ? -1 : dp[n-1];

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

    cout<<LIS(a,n)<<endl;

  }

  return 0;
}
