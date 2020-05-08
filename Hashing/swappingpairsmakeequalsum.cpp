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


ll bizan(ll a[],unordered_map<ll,ll> mp,ll x,ll n){

  if(x%2 != 0)
    return -1;

  x/=2;

  fr(i,n){
    ll target = a[i] - x;
    if(mp.find(target) != mp.end())
      return 1;
  }

  return -1;
}

int main(){
  fast;
  ll t;
  cin>>t;
  while(t--){
    ll n,m;
    cin>>n>>m;
    ll a[n],b[m],suma=0,sumb=0;
    unordered_map<ll,ll> mp;
    fr(i,n){
      cin>>a[i];
      suma+=a[i];
    }
    fr(i,m){
      cin>>b[i];
      mp[b[i]] = 1;
      sumb+=b[i];
    }

    ll x = (suma - sumb);

    cout<<bizan(a,mp,x,n)<<endl;

  }
  return 0;
}
