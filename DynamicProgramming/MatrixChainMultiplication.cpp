#include<bits/stdc++.h>
using namespace std;

/*matrix(i)'s dimensions are a[i-1] X a[i]'*/

int dp[110][110];

int MCM(int a[],int i,int j){

  if(dp[i][j] != -1)
    return dp[i][j];

  //baseCase
  if(i >= j) //if > then no matrix , if == then only one matrix
    return 0;

  int mn = INT_MAX;

  //breaking into subproblem
  for(int k=i;k<j;k++){ //k<j since we need atleast one matrix on the left side

    int temp = MCM(a,i,k) + MCM(a,k+1,j) + a[i-1]*a[k]*a[j];//the product is the cost of multilying the matrixes i-1 to k and k+1 to j

    mn = min(mn,temp);
  }

  return dp[i][j] = mn;

}


int main(){
  int t;
  cin>>t;

  while(t--){

    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
      cin>>a[i];

    memset(dp,-1,sizeof(dp));

    cout<<MCM(a,1,n-1)<<endl;

  }

  return 0;
}
