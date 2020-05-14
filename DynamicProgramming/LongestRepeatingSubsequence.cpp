#include<bits/stdc++.h>
using namespace std;


int LRS(string a,int n){

  string b = a;

  int dp[n+1][n+1];

  //baseCase
  for(int i=0;i<n+1;i++){
    for(int j=0;j<n+1;j++){
      if(i == 0 || j == 0)//either one of the strings is empty
        dp[i][j] = 0;
    }
  }

  //choiceProgram
  for(int i=1;i<n+1;i++){
    for(int j=1;j<n+1;j++){

      if(a[i-1] == b[j-1] && i != j)//similar chars of the string but in different positions, i.e., same element cannot count for itself in the duplicate string
        dp[i][j] = 1 + dp[i-1][j-1];
      else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

    }
  }

  return (dp[n][n]);

}


int main(){
  int t;
  cin>>t;

  while(t--){

    int n;
    cin>>n;

    string a;
    cin>>a;

    cout<<LRS(a,n)<<endl;
  }

  return 0;
}
