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

vector<pair<ll,ll>> bizan(ll a[],ll m,unordered_map<ll,ll> mp,ll k){
  vector<pair<ll,ll>> v;

  fr(i,m){
    ll target = k - a[i];
    auto it = mp.find(target);

    if(it == mp.end())
      continue;

    v.pb(make_pair(a[i],target));
  }

  return v;
}

int main(){
  fast;
  ll t;
  cin>>t;
  while(t--){
    ll m,n,k;
    cin>>m>>n>>k;
    ll a[m];
    unordered_map<ll,ll> mp;

    fr(i,m)
      cin>>a[i];

    fr(i,n){
      ll x;
      cin>>x;
      mp[x] = x;
    }

    vector<pair<ll,ll>> v = bizan(a,m,mp,k);

    if(v.size()){
      sort(v.begin(),v.end());
      fr(i,v.size()-1)
        cout<<v[i].first<<" "<<v[i].second<<", ";
      cout<<v[v.size()-1].first<<" "<<v[v.size()-1].second<<endl;
    }
    else cout<<-1<<endl;
  }
  return 0;
}
