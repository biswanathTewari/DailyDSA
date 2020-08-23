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

vector<ll> subsetSum(ll a[],ll n,ll sum){

  ll dp[n+1][sum+1];

  memset(dp,-1,sizeof(dp));

  //base case
  fr(i,n+1){
    fr(j,sum+1){
      if(i == 0)//if no elements
        dp[i][j] = false;

      if(j == 0)//if sum = 0
        dp[i][j] = true;
    }
  }

  //choice program
  fr1(i,1,n+1,1){
    fr1(j,1,sum+1,1){

      //we dont take it
      if(a[i-1] > j)
        dp[i][j] = dp[i-1][j];

      //either we take it or we dont take it
      if(a[i-1] <= j)
        dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];

    }
  }

  vector<ll> v;

  for(int i=0;i<sum+1;i++)
    if(dp[n][i] == true)
      v.pb(i);

  return v;

}


int main(){
  fast;
  ll t;
  cin>>t;
  while(t--){

    ll n;
    cin>>n;
    ll a[n];

    ll sumation = 0,mn=INT_MAX;
    fr(i,n){
      cin>>a[i];
      sumation+=a[i];
    }

    vector<ll> v = subsetSum(a,n,sumation);

    for(auto i:v){
      mn = min(mn,sumation - (2*i));
    }

    cout<<mn<<endl;

  }
  return 0;
}
