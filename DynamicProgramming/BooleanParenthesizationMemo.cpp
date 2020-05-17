#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

int dp[202][202][2];


int BP(string a,int i,int j,int tb){

  if(dp[i][j][tb] != -1)
    return dp[i][j][tb];

  //baseCase
  if(i>j)//no chars
    return dp[i][j][tb] = 0;

  if( i == j){//if only one element
    if(tb  == 1)//what we need is true value
      return dp[i][j][tb] = (a[i] == 'T')? 1 : 0;
    else return dp[i][j][tb] = (a[i] == 'F')? 1 : 0;
  }


  //partionFinding
  int ans = 0;
  for(int k=i+1;k<j;k+=2){

    int lt ;//if the left side is true
    int lf ;//if the left side is false
    int rt ;//if the right side is true
    int rf ;//if the right side is fals


    if(dp[i][k-1][1]!=-1)
            lt=dp[i][k-1][1];
        else
        {
            lt=BP(a,i,k-1,1);
            dp[i][k-1][1]=lt;
        }
        if(dp[i][k-1][0]!=-1)
            lf=dp[i][k-1][0];
        else
        {
            lf=BP(a,i,k-1,0);
            dp[i][k-1][0]=lf;
        }
        if(dp[k+1][j][1]!=-1)
            rt=dp[k+1][j][1];
        else
        {
            rt=BP(a,k+1,j,1);
            dp[k+1][j][1]=rt;
        }
        if(dp[k+1][j][0]!=-1)
            rf=dp[k+1][j][0];
        else
        {
            rf=BP(a,k+1,j,0);
            dp[k+1][j][0]=rf;
        }

    if(a[k] == '|'){
      if(tb == 1)
        ans += lt * rt + lf * rt + lt * rf; //counting total ways if we need true
      else ans += lf * rf ;//if we need false
    }

    if(a[k] == '&'){
      if(tb == 1)
        ans += lt * rt;
      else ans += lf * rf + lt * rf + lf * rt;
    }

    if(a[k] == '^'){
      if(tb == 1)
        ans += lf * rt + lt * rf ;
      else ans += lt * rt + lf * rf;
    }

  }

  return dp[i][j][tb] = ans % 1003;

}


int main(){
  fast;
  int t;
  cin>>t;

  while(t--){

    int n;
    cin>>n;

    string a;
    cin>>a;

    memset(dp,-1,sizeof(dp));

    cout<<BP(a,0,n-1,1)<<endl;

  }

  return 0;
}
