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

ll freq[61];

bool cmp(ll a,ll b){
  if(freq[a] == freq[b])
    return a < b;
  return freq[a] > freq[b];
}

int main(){
  fast;
  ll t;
  cin>>t;
  while(t--){
    ll n;
    cin>>n;
    fill(freq,freq+61,0);
    ll a[n];
    fr(i,n){
      cin>>a[i];
      freq[a[i]]++;
    }
    sort(a,a+n,cmp);
    fr(i,n)
      cout<<a[i]<<" ";
    cout<<endl;
  }
  return 0;
}
