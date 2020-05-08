//biZanXsolutions
#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define MOD 1000000007
#define ll long long int
#define ld long double
#define sl unsigned long long int
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


bool subsetSum(ll a[],ll n,ll sum){

  bool dp[n+1][sum+1];

  memset(dp,-1,sizeof(dp));

  //base case
  fr(i,n+1)
    fr(j,sum+1){
      //if there are elements
      if(i == 0)
        dp[i][j] = false;

      //if the sum is 0
      if(j == 0)
          dp[i][j] = true;
    }

  //choice program
  fr1(i,1,n+1,1)
    fr1(j,1,sum+1,1){

    if(a[i-1] > j)
      dp[i][j] = dp[i-1][j];
    else dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j] ;

    }


  return dp[n][sum];
}


int main(){
  fast;
  ll t;
  cin>>t;
  while(t--){
    ll n,sum = 0;
    cin>>n;

    ll a[n];

    fr(i,n){
      cin>>a[i];
      sum+=a[i];
    }

    if(sum%2!=0)
      cout<<"NO"<<endl;
    else{
      if(subsetSum(a,n,sum/2))
        cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }

  }
  return 0;
}
