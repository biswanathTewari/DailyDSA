#include<bits/stdc++.h>
using namespace std;

int dp[1002][1002];
int val[1002];
int wgh[1002];


int knapsack(int index,int curW){

  //base condition
  for(int i=0;i<index+1;i++){
    for(int j=0;j<curW+1;j++){
        if(i == 0 || j == 0)
          dp[i][j] = 0;
    }
  }


  //choice program
  for(int i=1;i<index+1;i++){
    for(int j=1;j<curW+1;j++){

      if(wgh[i-1] > j)
        dp[i][j] = dp[i-1][j]; //accrdn to recursion , if so then we go downwards

      if(wgh[i-1] <= j)
        dp[i][j] = max(val[i-1]+dp[i][j-wgh[i-1]] , dp[i-1][j]); //either we take or we dnt bfr goin down(accrdn to recur)
        //if we take the item , we still keep checking the same item without going forward but with reduced capacity.
    }
  }

  return  dp[index][curW];
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

    cout<<knapsack(n,w)<<endl;
  }
  return 0;
}
