#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

int dp[11][51];


int ED(int e,int f){

  if(dp[e][f] != -1)
    return dp[e][f];

  //baseCase
  if(e == 1)//if only one egg then for the worst case(atleast), we need to check each floor from bottom to up
    return dp[e][f] = f;

  if(f == 0 || f == 1)
    return dp[e][f] = f;


  int mn = INT_MAX;

  for(int k = 1;k<=f;k++){

    int broke ;
    int unbroke ;//check remaining floors

    if(dp[e-1][k-1] != -1)
      broke = dp[e-1][k-1];
    else broke = ED(e-1,k-1);

    if(dp[e][f-k] != -1)
      unbroke = dp[e][f-k];
    else unbroke = ED(e,f-k);

    int temp = max(broke,unbroke) + 1;

    mn = min(mn,temp);

  }

  return dp[e][f] = mn;
}


int main(){
  fast;
  int t;
  cin>>t;
  while(t--){

    int e,f;

    cin>>e>>f;

    memset(dp,-1,sizeof(dp));

    cout<<ED(e,f)<<endl;

  }

  return 0;
}
