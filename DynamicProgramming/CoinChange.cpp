/*This problem is a variation of unbouned knapsack and counting the ways for subset sum */

#include<bits/stdc++.h>
using namespace std;

int coinChange(int a[],int n,int w){

  int dp[n+1][w+1];

  //baseCase
  for(int i=0;i<n+1;i++){
    for(int j=0;j<w+1;j++){

      //no coins
      if(i == 0)
        dp[i][j] = 0;//0 ways

      //0 value of sum
      if(j == 0)
        dp[i][j] = 1;//1 way
    }
  }

  //choiceProgram
  for(int i=1;i<n+1;i++){
    for(int j=1;j<w+1;j++){

      //if coin is greater than the sum
      if(a[i-1] > j)
        dp[i][j] = dp[i-1][j];//we dont take it and move forward

      //if coin is less than the sum required
      if(a[i-1] <= j)
        dp[i][j] = dp[i][j-a[i-1]] + dp[i-1][j];//since unbounded we dont move if success and '+' to count the no.of ways

    }
  }

  return dp[n][w];
}


int main(){
  int t;
  cin>>t;
  while(t--){
    int n,w;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++)
      cin>>a[i];

    cin>>w;//the sum of the coins

    cout<<coinChange(a,n,w)<<endl;
  }
  return 0;
}
