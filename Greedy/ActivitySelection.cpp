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

bool cmp(pair<ll,ll> a,pair<ll,ll> b){
  return a.second < b.second ;
}

int main(){
  fast;
  ll t;
  cin>>t;
  while(t--){
    ll n;
    cin>>n;
    ll a[n],b[n];

    fr(i,n)
      cin>>a[i];

    fr(i,n)
      cin>>b[i];

    vector<pair<ll,ll>> v;

    fr(i,n)
      v.pb(make_pair(a[i],b[i]));

    sort(v.begin(),v.end(),cmp);

    ll prev = 0;
    ll count = 0;
    fr(i,v.size()){
      if(v[i].first >= prev){
        count++;
        prev = v[i].second;
      }
    }

    cout<<count<<endl;

  }
  return 0;
}
