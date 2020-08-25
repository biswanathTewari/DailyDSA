/*
https://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed/0
DailyDSA: bizan7X
*/

#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)


ll consecutive(ll n,ll ending){


  ll dp[n+1][2]; //dp[i][0] keeps hold of the numbers ending with zero and dp[i][1] numbers ending with 1

  //baseCase
  for(ll j=0;j<2;j++)
    dp[1][j] = 1; //if the size of the number is 1 , only 1 way for numbers endign with 0 and 1 each



  //ChoiceProgram
  for(ll i=2;i<=n;i++){
    for(ll j=0;j<2;j++){

      if(j == 0) //if we are looking for the numbers ending with 0
        dp[i][j] = ((dp[i-1][0]%MOD) + (dp[i-1][1]%MOD))%MOD; //adding a 0 to the numbers ending with (0 + 1)
      else dp[i][j] = (dp[i-1][0])%MOD; //adding a 1 with the number ending with 0 only.

    }
  }

  return (dp[n][0])%MOD; //returns dp[target][0] + dp[target][1] .

}


int main(){
  fast;

  int t;
  cin>>t;

  while(t--){

    ll n;
    cin>>n;

    cout<<consecutive(n+1,0)<<endl;

  }

  return 0;
}
