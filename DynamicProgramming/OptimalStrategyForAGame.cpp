#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int Optimal(int a[],int n,int i,int j){

  if(dp[i][j] != -1)
    return dp[i][j];

  //baseCase
  if(i == j)//range is 1
    return dp[i][j] = a[i];

  if(i+1 == j)//range is 2
    return dp[i][j] = max(a[i],a[j]);


  //choiceProgram
  dp[i][j] = max((a[i]+min(Optimal(a,n,i+2,j),Optimal(a,n,i+1,j-1))) , (a[j]+min(Optimal(a,n,i,j-2),Optimal(a,n,i+1,j-1))));

  return dp[i][j];

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

    memset(dp,-1,sizeof(dp));

    cout<<Optimal(a,n,0,n-1)<<endl;

  }

  return 0;
}
