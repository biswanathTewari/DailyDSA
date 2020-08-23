/*variation of LCS : bottom up approach O(N^2)*/
#include<bits/stdc++.h>
using namespace std;

int LCS(string a,string b,int n,int m){

  int dp[n+1][m+1];

  /*convertion from a -> b*/

  //baseCase
  for(int i=0;i<n+1;i++){
    for(int j=0;j<m+1;j++){

      if(i == 0)//if the string a is empty
        dp[i][j] = j;//j no.of insertions

      if(j == 0)//if the string b is empty
        dp[i][j] = i;//i no.of deletions
    }
  }

  //choiceProgram
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){

      if(a[i-1] == b[j-1])
        dp[i][j] = dp[i-1][j-1];//no actions
      else{

        int replacements = dp[i-1][j-1];
        int inserts = dp[i][j-1]; //converting a[0 to i] -> b[0 to j-1] and then adding an element b[j]
        int deletions = dp[i-1][j];//reverse of insertion

        dp[i][j] = 1 + min(replacements,min(inserts,deletions));

      }

    }
  }

  return dp[n][m];

}


int main(){
  int t;
  cin>>t;

  while(t--){

    int n,m;
    cin>>n>>m;

    string a,b;
    cin>>a>>b;

    cout<<LCS(a,b,n,m)<<endl;

  }

  return 0;
}
