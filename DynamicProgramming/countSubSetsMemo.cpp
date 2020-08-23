//biZanXsolutions
#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define MOD 1000000007
#define sl long long int
#define ld long double
#define ll unsigned long long int
#define str string
#define vll vector<ll>
#define pb push_back
#define fr(i,n) for(ll (i) = 0; (i) <(n) ; (i)=(i+1))
#define frn(i,n) for(ll (i) = 1; (i) <=(n) ; (i)=(i+1))
#define frev(i,n) for(ll (i) = n-1; (i) >=(0) ; (i)--)
#define fr1(j,a,b,c) for(ll (j) = a; (j) <b ; (j)=(j+c))
#define bw(t) while(t--)
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
typedef pair<ll, pair<ll, ll>> xecs;

ll dp[1003][1003];
ll vis[1003][1003];


ll subsetSum(ll a[],ll n,ll sum){

  //base case
  if(sum == 0)
    return 1;

  if(n == 0)
    return 0;

  if(vis[n][sum] == 1)
    return dp[n][sum];


  //choice program

  if(a[n-1] > sum){
    dp[n][sum] = subsetSum(a,n-1,sum);
  }
  else dp[n][sum] = dp[n-1][sum-a[n-1]] + dp[n-1][sum];


  return dp[n][sum];
}


int main(){
  fast;
  ll t;
  cin>>t;
  while(t--){
    ll n,sum;
    cin>>n;

    ll a[n];

    memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(vis));

    fr(i,n){
      cin>>a[i];
    }

    cin>>sum;

    cout<<subsetSum(a,n,sum)<<endl;

  }
  return 0;
}
