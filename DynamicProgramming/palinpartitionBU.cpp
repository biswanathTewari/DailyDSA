/*this problem is a variation of MCM problem*/
#include<bits/stdc++.h>
using namespace std;


bool isPalin(string a,int l,int r){

  int n = r - l + 1;

  for(int i=0;i<n/2;i++)
    if(a[i+l] != a[r - i])
      return false;

  return true;

}


int PP(string a,int i,int j){

  int dp[j+2][j+2];

  //baseCase
  for(int ii=0;ii<j+2;ii++)
    for(int jj=0;jj<j+2;j++)
      if(ii>=jj || isPalin(a,ii,jj) ) //if empty string or only one char or if the string is a palindrome then 0 partitions is needed
        return dp[ii][jj] = 0;

  int mn = INT_MAX;

  //partionFinding
  for(int k=i;k<j;k++){

    int temp = PP(a,i,k) + PP(a,k+1,j) + 1;

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
