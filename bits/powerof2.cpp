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

int main(){
  ll t;
  cin>>t;
  vector<ll> v;
  v.pb(1);
  ll i=0;
  while(v[i]<=pow(10,18)){
    i++;
    v.pb(pow(2,i));
  }
  while(t--){
    ll n;
    cin>>n;
    ll f=0;
    fr(i,v.size())
      if(v[i]==n)
        f=1;
    if(f)
      cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}
