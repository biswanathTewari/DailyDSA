/*variation of unbouned knapsack*/
#include<bits/stdc++.h>
using namespace std;

int rodCutting(int a[],int l,int n){

  int dp[l+1][n+1];

  memset(dp,0,sizeof(dp));

  //baseCase
  for(int i=0;i<3+1;i++){
    for(int j=0;j<n+1;j++){

      //if there no sizes to cut
      if(i == 0)
        dp[i][j] = INT_MAX;//filling with infinity if the remaining uncutted portion cannot be cutted by other elements of array
    }
  }


  //choiceProgram
  for(int i=1;i<l+1;i++){
    for(int j=1;j<n+1;j++){

      //if we dont cut it
      if(a[i-1] > j)
        dp[i][j] = dp[i-1][j];

      //if we cut it
      if(a[i-1] <= j)
        dp[i][j] = min(1+dp[i][j-a[i-1]],dp[i-1][j]);//since a variation of unbouned knapsack we stay at index i until unsuccess

    }
  }




  return dp[l][n];

}



int main(){

  int t;
  cin>>t;

  while(t--){

  int n;
  cin>>n;

  int a[10] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

  cout<<rodCutting(a,10,n)<<endl;

  }
  return 0;
}
