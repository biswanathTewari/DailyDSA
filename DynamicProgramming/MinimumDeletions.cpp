/*variation of longest common subsequence problem and lonest palindromic subsequence*/
#include<bits/stdc++.h>
using namespace std;


int LPS(string a){

  int n = a.length();
  string b = a;

  reverse(b.begin(),b.end());

  int dp[n+1][n+1];

  //baseCase
  for(int i=0;i<n+1;i++){
    for(int j=0;j<n+1;j++){
      if(i == 0 || j == 0)//if anyone of them is empty
        dp[i][j] = 0;
    }
  }


  //choiceProgram
  for(int i=1;i<n+1;i++){
    for(int j=1;j<n+1;j++){

      if(a[i-1] == b[j-1])
        dp[i][j] = dp[i-1][j-1] + 1;
      else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

    }
  }

  return dp[n][n];

}


int main(){

  int t;
  cin>>t;

  while(t--){

    string a;
    cin>>a;

    int lps = LPS(a);

    cout<<a.length()-lps<<endl; //a.length - lps(longest common subsequence) is the unwanted part

  }

  return 0;
}
