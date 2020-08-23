/*this problem is a variation of MCM problem*/
#include<bits/stdc++.h>
using namespace std;


int dp[1001][1001];


bool isPalin(string a,int l,int r){

  int n = r - l + 1;

  for(int i=0;i<n/2;i++)
    if(a[i+l] != a[r - i])
      return false;

  return true;

}


int PP(string a,int i,int j){

  //baseCase
  if(i>=j || isPalin(a,i,j) ) //if empty string or only one char or if the string is a palindrome then 0 partitions is needed
    return 0;

  if(dp[i][j] != -1)
      return dp[i][j];

  int mn = INT_MAX;

  //partionFinding
  for(int k=i;k<j;k++){

    int left;
    int right;

    if(dp[i][k] == -1)
      left = PP(a,i,k);
    else left = dp[i][k];

    if(dp[k+1][j] == -1)
      right = PP(a,k+1,j);
    else right = dp[k+1][j];

    int temp = left + right + 1;

    mn = min(mn,temp);

  }

  return dp[i][j] = mn;

}

int main(){
  int t;
  cin>>t;

  while(t--){

    string a;
    cin>>a;

    memset(dp,-1,sizeof(dp));

    cout<<PP(a,0,a.length()-1)<<endl;

  }

  return 0;
}
