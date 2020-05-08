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

ll a[100][100];

void check(ll x,ll y,ll k,ll r,ll m,ll n){
  if(a[x][y]==r){
    a[x][y]=k;
    if(x-1>=0)
      check(x-1,y,k,r,m,n);
    if(x+1<m)
      check(x+1,y,k,r,m,n);
    if(y+1<n)
      check(x,y+1,k,r,m,n);
    if(y-1>=0)
      check(x,y-1,k,r,m,n);
  }
  return ;
}

void printm(ll m,ll n){
  fr(i,m)
    fr(j,n)
      cout<<a[i][j]<<" ";
  cout<<endl;
}

int main(){
  fast;
  ll t;
  cin>>t;
  while(t--){
    ll m,n;
    cin>>m>>n;
    memset(a,0,sizeof(a));
    fr(i,m)
      fr(j,n)
        cin>>a[i][j];
    ll x,y,k,r;
    cin>>x>>y>>k;
    if(a[x][y]!=k)
      check(x,y,k,a[x][y],m,n);
    printm(m,n);
  }
  return 0;
}
