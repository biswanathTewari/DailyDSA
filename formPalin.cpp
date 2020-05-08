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

ll dp[41][41];

ll dpbiZanX(string s,ll a,ll b){
  frev(i,b){
    for(ll j=i;j<b;j++){
      if(i==j)
        dp[i][j]=0;
      else if(s[i]==s[j])
        dp[i][j]+=dp[i+1][j-1];
      else
        dp[i][j]=1+min(dp[i+1][j],dp[i][j-1]);
    }
  }
  return dp[0][b-1];
}

int main(){
  ll t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    ll n=s.length();
    memset(dp,0,sizeof(dp)); //initialise the 2D array with 0
    ll r=dpbiZanX(s,0,s.length());
    cout<<r<<endl;
  }
  return 0;
}
