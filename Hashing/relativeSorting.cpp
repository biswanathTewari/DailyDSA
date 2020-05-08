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

ll lim = 10E6;
ll *loc = new ll[lim+1];

bool cmp(ll a,ll b){
  return loc[a] < loc[b];
}

int main(){
  fast;
  ll t;
  cin>>t;
  while(t--){
    ll n,m;
    cin>>n>>m;
    ll a[n],b[n];
    fill(loc,loc+lim,-1);
    fr(i,n)
      cin>>a[i];
    fr(i,m)
      cin>>b[i];
    fr(i,m)
      loc[b[i]] = i;
    vll left,real;
    fr(i,n)
      if(loc[a[i]] == -1)
        left.pb(a[i]);
      else real.pb(a[i]);
    sort(real.begin(),real.end(),cmp);
    sort(left.begin(),left.end());
    fr(i,real.size())
      cout<<real[i]<<" ";
    fr(i,left.size())
      cout<<left[i]<<" ";
    cout<<endl;
  }
  return 0;
}
