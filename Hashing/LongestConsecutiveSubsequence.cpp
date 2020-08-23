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
  fast;
  ll t;
  cin>>t;
  while(t--){
    ll n;
    cin>>n;
    ll a[n];
    vll v;
    ll f[100005];
    fill(f,f+100005,0);

    fr(i,n){
      cin>>a[i];
      f[a[i]] = 1;
    }

    fr(i,100005)
      if(f[i]==1)
        v.pb(i);

    ll m=0,count=0,prev;

    prev = v[0];
    count++;

    fr1(i,1,v.size(),1){
      if(v[i]-prev > 1){
        m = max(m,count);
        count = 0;
      }
      count++;
      prev = v[i];
    }

    m = max(m,count);

    cout<<m<<endl;

  }
  return 0;
}
