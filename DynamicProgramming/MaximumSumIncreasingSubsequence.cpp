/*variation of LIS : O(N^2)*/
#include<bits/stdc++.h>
using namespace std ;

int LIS(int a[],int n){

  int dp[n];

  for(int i=0;i<n;i++){
    dp[i] = a[i];
  }

  int mx = INT_MIN;

  for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){

      if(a[j] < a[i])
        dp[i] = max(dp[i] , a[i]+dp[j]);

    }
    if(dp[i] > mx)
      mx = dp[i];
  }

  return mx;

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
