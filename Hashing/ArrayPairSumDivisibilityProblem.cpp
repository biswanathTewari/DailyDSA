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

ll bizan(ll a[],ll n,ll k,unordered_map<ll,ll> use,unordered_map<ll,vector<ll>> tar){

  if(n%2!=0)
    return -1;

  fr(i,n){
    if(use[a[i]] == 1)
      continue;

    ll target = (k-(a[i]%k));

    if(tar.find(target) == tar.end())
      return -2;

    ll x = tar[target][tar[target].size()-1];

    tar[target].pop_back();

    while(tar[target].size()!=0 && use[x]){
      x = tar[target][tar[target].size()-1];
      tar[target].pop_back();
    }

    if(use[x] == 1)
      return -3;
      
    use[a[i]] = 1;
    use[x] = 1;

    if(tar[target].size() == 0)
      tar.erase(target);
  }

  return 1;

}


int main(){
  fast;
  ll t;
  cin>>t;
  while(t--){
    ll n,k;
    cin>>n;
    ll a[n];
    unordered_map<ll,ll> use;// if the number has been paired up or not
    unordered_map<ll,vector<ll>> tar;

    fr(i,n){
      cin>>a[i];
    }

    cin>>k;

    fr(i,n){
      use[a[i]] = 0;
      ll x = a[i]%k;
      if(x)
      tar[x].pb(a[i]);
      else tar[k].pb(a[i]);
    }

    ll d = bizan(a,n,k,use,tar);

    if(d == 1)
      cout<<"True"<<endl;
    else cout<<"False"<<endl;
  }
  return 0;
}
