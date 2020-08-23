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

void bizan(unordered_map<ll,vector<pair<ll,ll>>> mp,ll a[],ll n,ll k){
  set<vll> v;
  ll flag = 0;
  fr(i,n)
    fr1(j,i+1,n,1)
      for(auto it : mp[k-a[i]-a[j]])
        if(it.first != i && it.first != j && it.second != i && it.second != j){
          vector<ll> sam = {a[i],a[j],a[it.first],a[it.second]};
          sort(sam.begin(),sam.end());
          v.insert(sam);
          flag = 1;
        }
  if(flag){
    for(auto i :v){
      fr(j,4)
        cout<<i[j]<<" ";
      cout<<"$";
    }
  }
  else cout<<"-1"<<endl;
}

int main(){
  fast;
  ll t;
  cin>>t;
  while(t--){
    ll n,k;
    unordered_map<ll,vector<pair<ll,ll>>> mp;
    cin>>n>>k;
    ll a[n];
    fr(i,n)
      cin>>a[i];
    fr(i,n)
      fr1(j,i+1,n,1)
        mp[a[i]+a[j]].push_back(make_pair(i,j));
    bizan(mp,a,n,k);
    cout<<endl;
  }
  return 0;
}
