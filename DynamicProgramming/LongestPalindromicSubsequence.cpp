/*variation of longest common subsequence problem*/
#include<bits/stdc++.h>
using namespace std;


int LPS(string a,string b){

  int n = a.length();
  int m = b.length();

  int dp[n+1][m+1];

  //memset(dp,0,sizeof(dp));

  //baseCase
  for(int i=0;i<n+1;i++){
    for(int j=0;j<m+1;j++){
      if(i == 0 || j == 0)
        dp[i][j] = 0;
    }
  }


  //choiceProgram
  for(int i=1;i<n+1;i++){
    for(int j=1;j<n+1;j++){

      if(a[i-1] == b[j-1])
        dp[i][j] = 1+dp[i-1][j-1]; //if matches
      else dp[i][j] = max(dp[i-1][j],dp[i][j-1]); //trying out the two possible combinations

    }
  }

  return dp[n][m];

}


int main(){
  int t;
  cin>>t;

  while(t--){
    string a,b;

    cin>>a;
    b = a;

    reverse(b.begin(),b.end());

    cout<<LPS(a,b)<<endl;
  }

  return 0;
}
