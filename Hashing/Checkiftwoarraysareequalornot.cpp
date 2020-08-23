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

ll bizan(unordered_map<ll,ll> mp,ll b[],ll n){

  fr(i,n){
    if(mp.find(b[i]) == mp.end())
      return 0;
    mp[b[i]]--;
    if(mp[b[i]] == 0)
      mp.erase(b[i]);
  }

  if(mp.size() == 0)
    return 1;

  return 0;
}

int main(){
  fast;
  ll t;
  cin>>t;
  while(t--){
    ll n;
    cin>>n;
    unordered_map<ll,ll> mp;
    ll b[n];

    fr(i,n){
      ll x;
      cin>>x;
      if(mp.find(x) == mp.end())
        mp[x] = 1;
      else mp[x]++;
    }

    fr(i,n)
      cin>>b[i];

    cout<<bizan(mp,b,n)<<endl;
  }
  return 0;
}
