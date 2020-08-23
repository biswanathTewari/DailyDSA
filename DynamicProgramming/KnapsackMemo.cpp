#include<bits/stdc++.h>
using namespace std;

int dp[1002][1002];
int val[1002];
int wgh[1002];


int knapsack(int index,int curW){

  if(index == -1 || curW == 0)
    return 0;

  if(dp[index][curW] != -1)
    return dp[index][curW];

  if(wgh[index] > curW)
    return dp[index][curW] = knapsack(index-1,curW);

  if(wgh[index] <= curW)
    return dp[index][curW] = max(knapsack(index-1,curW),val[index]+knapsack(index-1,curW-wgh[index]));
}


int main(){
  int t;
  cin>>t;
  while(t--){
    int n,w;
    cin>>n>>w;

    memset(dp,-1,sizeof(dp));

    for(int i=0;i<n;i++)
      cin>>val[i];

    for(int i=0;i<n;i++)
      cin>>wgh[i];

    cout<<knapsack(n-1,w)<<endl;
  }
  return 0;
}
